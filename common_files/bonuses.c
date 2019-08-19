/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonuses.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubartemi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 14:01:56 by ubartemi          #+#    #+#             */
/*   Updated: 2019/08/19 14:03:12 by ubartemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_check_flags(t_flags *flags_struct)
{
	if (flags_struct->debug_mode > 1
			|| flags_struct->count_mode > 1
			|| flags_struct->file_mode > 1)
		ft_error();
}

void	ft_parse_flags_f(t_flags *f_struct, char **argv, char flag, int i)
{
	if (flag == 'v')
	{
		f_struct->debug_mode += 1;
		f_struct->sep_f = f_struct->sep_f == 0
			? i : f_struct->sep_f + 1;
	}
	else if (flag == 'c')
	{
		f_struct->count_mode += 1;
		f_struct->sep_f = f_struct->sep_f == 0
			? i : f_struct->sep_f + 1;
	}
	else if (flag == 'f')
	{
		f_struct->file_mode += 1;
		f_struct->sep_f = i + 1;
		f_struct->file_name = argv[i + 1];
	}
}

void	ft_parse_flags(t_flags *f_struct, char **ar)
{
	int i;
	int j;

	i = 1;
	while (i <= 3 && ar[i])
	{
		if (ar[i][0] == '-')
		{
			j = 1;
			while (j <= 3 && ar[i][j])
			{
				if (ar[i][j] == 'v' || ar[i][j] == 'c' || ar[i][j] == 'f')
					ft_parse_flags_f(f_struct, ar, ar[i][j], i);
				else if ((ar[i][j] < 48 || ar[i][j] > 57)
						&& ar[i][j] != 32 && ar[i][j] != '-')
					ft_error();
				j++;
			}
		}
		i++;
	}
	ft_check_flags(f_struct);
}

void	ft_write_file(t_flags *flags_struct, t_stacks *main_struct)
{
	if ((main_struct->fd = open(flags_struct->file_name,
					O_CREAT | O_RDWR | O_APPEND
					| O_TRUNC, S_IWRITE | S_IREAD)) == -1)
	{
		ft_putstr_fd("Open/create file error\n", 2);
		ft_list_clear(&main_struct->a);
		ft_list_clear(&main_struct->b);
		exit(1);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubartemi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 14:03:45 by ubartemi          #+#    #+#             */
/*   Updated: 2019/08/19 14:04:53 by ubartemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_files/push_swap.h"

void	ft_apply_commands(t_stacks *main_struct, char *command)
{
	(main_struct->counter)++;
	if (!ft_strcmp("sa", command))
		SA;
	else if (!ft_strcmp("sb", command))
		SB;
	else if (!ft_strcmp("ss", command))
		SS;
	else if (!ft_strcmp("pb", command))
		PB;
	else if (!ft_strcmp("pa", command))
		PA;
	else if (!ft_strcmp("ra", command))
		RA;
	else if (!ft_strcmp("rb", command))
		RB;
	else if (!ft_strcmp("rr", command))
		RR;
	else if (!ft_strcmp("rra", command))
		RRA;
	else if (!ft_strcmp("rrb", command))
		RRB;
	else if (!ft_strcmp("rrr", command))
		RRR;
	else
		ft_error();
}

void	ft_check_sort(t_stacks *m_struct, t_flags f_struct)
{
	t_lis *begin;

	if (!m_struct->a)
		return ;
	begin = m_struct->a;
	while (m_struct->a && m_struct->a->next)
	{
		if ((m_struct->a->num > m_struct->a->next->num) || m_struct->b)
		{
			ft_putstr("\033[31;1mKO\033[0m\n");
			exit(1);
		}
		m_struct->a = m_struct->a->next;
	}
	m_struct->a = begin;
	ft_putstr("\033[32;1mOK\033[0m\n");
	if (f_struct.count_mode)
	{
		ft_putnbr(m_struct->counter);
		ft_putchar('\n');
	}
}

void	ft_change_fd(t_stacks *m_struct, t_flags *f_struct)
{
	if ((m_struct->fd = open(f_struct->file_name, O_RDONLY)) == -1)
	{
		ft_putstr_fd("Open/create file error\n", 2);
		ft_list_clear(&m_struct->a);
		ft_list_clear(&m_struct->b);
		exit(1);
	}
}

int		main(int argc, char **argv)
{
	t_stacks	m_struct;
	t_flags		f_struct;
	char		*command;

	ft_initialization(&f_struct, &m_struct, 0);
	if (argc < 2)
		ft_show_usage_ch();
	if (!(ft_parse_fill(&m_struct, &f_struct, argc, argv)))
		ft_error();
	ft_check_duplicates(&m_struct);
	if (f_struct.file_mode)
		ft_change_fd(&m_struct, &f_struct);
	while (get_next_line(m_struct.fd, &command) > 0)
	{
		ft_apply_commands(&m_struct, command);
		if (f_struct.debug_mode == 1)
			ft_debag(m_struct.a, m_struct.b, command);
		free(command);
	}
	ft_check_sort(&m_struct, f_struct);
	if (f_struct.file_mode)
		close(m_struct.fd);
	ft_list_clear(&m_struct.a);
	ft_list_clear(&m_struct.b);
	return (0);
}

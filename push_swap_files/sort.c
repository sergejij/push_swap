/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubartemi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 14:57:16 by ubartemi          #+#    #+#             */
/*   Updated: 2019/08/19 14:58:23 by ubartemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_stack2(t_stacks *main_struct)
{
	if (main_struct->a->num > main_struct->a->next->num)
		ft_print_command(main_struct, "sa");
}

void	ft_sort_stack3(t_stacks *main_struct)
{
	int		first;
	int		second;
	int		third;

	first = main_struct->a->num;
	second = main_struct->a->next->num;
	third = main_struct->a->next->next->num;
	if (first > second && second < third && first < third)
		ft_print_command(main_struct, "sa");
	else if (third < second && second < first)
	{
		ft_print_command(main_struct, "sa");
		ft_print_command(main_struct, "rra");
	}
	else if (first > second && second < third && third < first)
		ft_print_command(main_struct, "ra");
	else if (first < second && first < third && second > third)
	{
		ft_print_command(main_struct, "sa");
		ft_print_command(main_struct, "ra");
	}
	else if (first < second && first > third && second > third)
		ft_print_command(main_struct, "rra");
}

int		ft_check_sort_ps(t_stacks main_struct)
{
	t_lis *begin;

	if (!main_struct.a)
		return (0);
	begin = main_struct.a;
	while (main_struct.a && main_struct.a->next)
	{
		if (main_struct.a->num > main_struct.a->next->num)
			return (0);
		main_struct.a = main_struct.a->next;
	}
	main_struct.a = begin;
	return (1);
}

int		is_ready_sort(t_stacks *main_struct)
{
	if (ft_check_sort_ps(*main_struct) && !(main_struct->b))
		return (1);
	return (0);
}

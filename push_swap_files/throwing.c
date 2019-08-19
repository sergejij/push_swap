/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   throwing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubartemi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 14:59:58 by ubartemi          #+#    #+#             */
/*   Updated: 2019/08/19 15:00:42 by ubartemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_find_poss_for_less_throws_a(t_stacks main_struct)
{
	t_lis	*begin;
	int		result;
	int		count_oper;

	result = 0;
	count_oper = main_struct.a_len + main_struct.b_len;
	begin = main_struct.b;
	while (main_struct.b)
	{
		if (main_struct.b->common_and_pos_a_b[0] < count_oper)
		{
			count_oper = main_struct.b->common_and_pos_a_b[0];
			result = main_struct.b->common_and_pos_a_b[1];
		}
		main_struct.b = main_struct.b->next;
	}
	main_struct.b = begin;
	return (result);
}

int		ft_find_poss_for_less_throws_b(t_stacks main_struct)
{
	t_lis	*begin;
	int		result;
	int		count_oper;

	result = 1;
	count_oper = main_struct.a_len + main_struct.b_len;
	begin = main_struct.b;
	while (main_struct.b)
	{
		if (main_struct.b->common_and_pos_a_b[0] < count_oper)
		{
			count_oper = main_struct.b->common_and_pos_a_b[0];
			result = main_struct.b->common_and_pos_a_b[2];
		}
		main_struct.b = main_struct.b->next;
	}
	main_struct.b = begin;
	return (result);
}

void	ft_make_throws(t_stacks *main_struct)
{
	int item_a;
	int item_b;

	item_a = ft_find_poss_for_less_throws_a(*main_struct);
	item_b = ft_find_poss_for_less_throws_b(*main_struct);
	ft_move_common(main_struct, item_a, item_b);
}

void	ft_throwing(t_stacks *main_struct)
{
	main_struct->min_actions = ft_check_quantity_throw(*main_struct);
	ft_make_throws(main_struct);
}

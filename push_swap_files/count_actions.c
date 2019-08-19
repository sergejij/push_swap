/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubartemi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 14:31:31 by ubartemi          #+#    #+#             */
/*   Updated: 2019/08/19 14:36:50 by ubartemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_count_no_gap(t_stacks *main_struct, int item)
{
	int		num_item;
	t_lis	*begin;

	begin = main_struct->a;
	num_item = 1;
	while (main_struct->a)
	{
		if (item > main_struct->a->num)
			num_item++;
		else
			break ;
		main_struct->a = main_struct->a->next;
	}
	main_struct->b->common_and_pos_a_b[1] = num_item;
	main_struct->a = begin;
	return (num_item);
}

int		ft_c_actions_in_a(t_stacks *main_struct, int item)
{
	if (!is_has_gap(*main_struct))
		return (ft_count_no_gap(main_struct, item));
	else
		return (ft_count_has_gap(main_struct, item));
}

int		ft_c_actions_in_b(t_lis *b, int item)
{
	int		num_item;
	t_lis	*begin;

	begin = b;
	num_item = 1;
	while (b)
	{
		if (b->num == item)
			break ;
		num_item++;
		b = b->next;
	}
	b->common_and_pos_a_b[2] = num_item;
	b = begin;
	return (num_item);
}

int		ft_count_d_and_s(t_stacks m_struct, t_lis *b, int item)
{
	int num_i_b;
	int num_i_a;
	int middle_b;
	int middle_a;
	int tmp;

	tmp = 0;
	middle_b = m_struct.b_len / 2;
	middle_a = m_struct.a_len / 2;
	num_i_b = ft_c_actions_in_b(b, item);
	num_i_a = ft_c_actions_in_a(&m_struct, item);
	if (num_i_b <= middle_b && num_i_a <= middle_a)
		while (num_i_b - 1 > 0 && num_i_a - 1 > 0)
			ft_change_meanings(&num_i_b, &num_i_a, &tmp, '-');
	else
		while (num_i_b < m_struct.b_len && num_i_a <= m_struct.a_len)
			ft_change_meanings(&num_i_b, &num_i_a, &tmp, '+');
	return (tmp + ft_count_moves(num_i_b, m_struct.b_len)
	+ ft_count_moves(num_i_a, m_struct.a_len));
}

int		ft_check_quantity_throw(t_stacks main_struct)
{
	int		current_item;
	t_lis	*begin;
	int		tmp_count_actions;
	int		result;

	result = main_struct.a_len + main_struct.b_len;
	begin = main_struct.b;
	while (main_struct.b)
	{
		current_item = main_struct.b->num;
		tmp_count_actions = ft_count_d_and_s(main_struct, begin, current_item);
		main_struct.b->common_and_pos_a_b[0] = tmp_count_actions;
		if (tmp_count_actions < result)
			result = tmp_count_actions;
		main_struct.b = main_struct.b->next;
	}
	main_struct.b = begin;
	return (result);
}

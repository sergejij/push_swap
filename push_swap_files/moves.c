/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubartemi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 14:51:35 by ubartemi          #+#    #+#             */
/*   Updated: 2019/08/19 14:52:42 by ubartemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_count_moves(int num_item, int len_stack)
{
	int middle;
	int counter;

	counter = 0;
	middle = len_stack / 2;
	if (len_stack == 1 || len_stack < num_item)
		return (0);
	if (num_item <= middle)
		while (num_item-- - 1)
			counter++;
	else
		while (num_item++ <= len_stack)
			counter++;
	return (counter);
}

void	ft_rotate_double(t_stacks *m_struct, int *num_item_a, int *num_item_b)
{
	int middle_b;
	int middle_a;
	int *len_b;
	int *len_a;

	len_b = &m_struct->b_len;
	len_a = &m_struct->a_len;
	middle_b = (*len_b) / 2;
	middle_a = (*len_a) / 2;
	if (*num_item_b <= middle_b && *num_item_a <= middle_a)
		while ((*num_item_b - 1) > 0 && (*num_item_a - 1) > 0)
		{
			ft_print_command(m_struct, "rr");
			(*num_item_b)--;
			(*num_item_a)--;
		}
	else if (*num_item_b >= middle_b && *num_item_a >= middle_a)
		while ((*num_item_a < *len_a && *num_item_a > middle_a)
		&& (*num_item_b <= *len_b && *num_item_b > middle_b))
		{
			ft_print_command(m_struct, "rrr");
			(*num_item_a)++;
			(*num_item_b)++;
		}
}

void	ft_rotate(t_stacks *m_struct, int n_item, int len_stack, char w_stack)
{
	int middle;

	middle = len_stack / 2;
	if (n_item <= middle)
		while (n_item-- - 1 > 0)
			w_stack == 'a' ? ft_print_command(m_struct, "ra")
			: ft_print_command(m_struct, "rb");
	else if (m_struct->is_first != 1)
		while (n_item <= len_stack && len_stack > 1)
		{
			w_stack == 'a' ? ft_print_command(m_struct, "rra")
			: ft_print_command(m_struct, "rrb");
			n_item++;
		}
	if (m_struct->b && w_stack == 'a')
		ft_print_command(m_struct, "pa");
}

void	ft_move_common(t_stacks *main_struct, int num_item_a, int num_item_b)
{
	if (is_need_double(main_struct, num_item_a, num_item_b))
		ft_rotate_double(main_struct, &num_item_a, &num_item_b);
	ft_rotate(main_struct, num_item_b, main_struct->b_len, 'b');
	ft_rotate(main_struct, num_item_a, main_struct->a_len, 'a');
}

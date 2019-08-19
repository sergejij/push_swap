/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubartemi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 14:54:19 by ubartemi          #+#    #+#             */
/*   Updated: 2019/08/19 14:56:53 by ubartemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_final_rotates(t_stacks *main_struct, int num_item, int a_len)
{
	int middle;

	middle = a_len % 2 == 0 ? a_len / 2 : (a_len / 2) + 1;
	if (num_item <= middle)
		while (num_item - 1)
		{
			ft_print_command(main_struct, "ra");
			num_item--;
		}
	else if (main_struct->is_first != 1)
		while (num_item <= a_len && a_len > 1)
		{
			ft_print_command(main_struct, "rra");
			num_item++;
		}
}

void	ft_eliminate_gap(t_stacks *main_struct, int a_len)
{
	int		pos_after_gap;
	t_lis	*begin;

	begin = main_struct->a;
	pos_after_gap = 1;
	if (!is_has_gap(*main_struct))
		return ;
	while (main_struct->a && main_struct->a->next)
	{
		if (main_struct->a->num > main_struct->a->next->num)
		{
			pos_after_gap++;
			break ;
		}
		pos_after_gap++;
		main_struct->a = main_struct->a->next;
	}
	main_struct->a = begin;
	ft_final_rotates(main_struct, pos_after_gap, a_len);
}

void	ft_push_swap(t_stacks *main_struct)
{
	int start_seq;
	int len_seq;

	len_seq = 0;
	start_seq = 0;
	ft_find_sort_sequence(main_struct->a, &start_seq, &len_seq);
	if (len_seq > 3 && !is_ready_sort(main_struct))
		ft_throw_seq(main_struct, start_seq, len_seq);
	else if (!is_ready_sort(main_struct))
		ft_throw_without_seq(main_struct);
	while (!is_ready_sort(main_struct))
	{
		if (main_struct->a_len == 2)
			ft_sort_stack2(main_struct);
		else if (main_struct->a_len == 3)
			ft_sort_stack3(main_struct);
		if (main_struct->b_len > 0)
		{
			ft_throwing(main_struct);
			main_struct->a_len += 1;
			main_struct->b_len -= 1;
		}
		if (main_struct->b_len == 0)
			ft_eliminate_gap(main_struct, main_struct->a_len);
	}
}

int		main(int argc, char **argv)
{
	t_stacks	main_struct;
	t_flags		flags_struct;

	ft_initialization(&flags_struct, &main_struct, 1);
	if (argc < 2)
		ft_show_usage_ps();
	if (!(ft_parse_fill(&main_struct, &flags_struct, argc, argv)))
		ft_error();
	ft_check_duplicates(&main_struct);
	if (flags_struct.file_mode)
		ft_write_file(&flags_struct, &main_struct);
	ft_push_swap(&main_struct);
	if (flags_struct.file_mode)
		close(main_struct.fd);
	ft_list_clear(&main_struct.a);
	ft_list_clear(&main_struct.b);
	return (0);
}

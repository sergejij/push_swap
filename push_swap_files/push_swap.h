/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubartemi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 15:57:39 by ubartemi          #+#    #+#             */
/*   Updated: 2019/08/19 15:03:52 by ubartemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../common_files/checker.h"

int		ft_count_moves(int num_item, int len_stack);
int		is_has_gap(t_stacks main_struct);
void	ft_throw_without_seq(t_stacks *main_struct);
void	ft_sort_stack2(t_stacks *main_struct);
void	ft_sort_stack3(t_stacks *main_struct);
int		ft_check_sort_ps(t_stacks main_struct);
int		is_ready_sort(t_stacks *main_struct);
void	ft_print_command(t_stacks *main_struct, char *command);
int		ft_count_has_gap(t_stacks *m_struct, int item);
void	ft_pos_after_gap(t_stacks *main_struct, int item,
		int *num_item, int *is_not_found);
void	ft_find_gap(t_stacks *main_struct, int item,
		int *num_item, int *is_not_found);
int		is_has_gap(t_stacks main_struct);
int		ft_count_no_gap(t_stacks *main_struct, int item);
int		ft_c_actions_in_a(t_stacks *main_struct, int item);
int		ft_c_actions_in_b(t_lis *b, int item);
int		ft_check_quantity_throw(t_stacks main_struct);
int		ft_count_moves(int num_item, int len_stack);
void	ft_move_common(t_stacks *main_struct, int num_item_a, int num_item_b);
void	ft_rotate(t_stacks *main_struct, int num_item,
		int len_stack, char which_stack);
void	ft_rotate_double(t_stacks *main_struct,
		int *num_item_a, int *num_item_b);
int		ft_find_poss_for_less_throws_a(t_stacks main_struct);
int		ft_find_poss_for_less_throws_b(t_stacks main_struct);
void	ft_make_throws(t_stacks *main_struct);
void	ft_throwing(t_stacks *main_struct);
void	ft_throw_without_seq(t_stacks *main_struct);
void	ft_throw_seq(t_stacks *main_struct, int start_seq, int len_seq);
void	ft_find_sort_sequence(t_lis *stack_a, int *start_seq, int *len_seq);
void	ft_write_file(t_flags *flags_struct, t_stacks *main_struct);
void	ft_parse_flags(t_flags *f_struct, char **argv);
void	ft_parse_flags_fill(t_flags *flags_struct,
		char **argv, char flag, int i);
void	ft_check_flags(t_flags *flags_struct);
int		ft_count_single(t_stacks *main_struct, int num_item, int len_stack);
int		ft_count_double(t_stacks *main_struct, int num_item_a, int num_item_b);
int		is_need_double(t_stacks *main_struct, int num_item_a, int num_item_b);

#endif

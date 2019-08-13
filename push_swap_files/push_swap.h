/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubartemi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 15:57:39 by ubartemi          #+#    #+#             */
/*   Updated: 2019/07/17 15:57:47 by ubartemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../common_files/checker.h"

/*---------------------------push_swap---------------------------*/

int	ft_count_moves(int num_item, int len_stack);
int ft_count_no_gap(t_stacks *main_struct, int item, int len_a);
int is_has_gap(t_stacks main_struct);
void ft_throw_without_seq(t_stacks *main_struct);

/*-----------------------------sort-----------------------------*/

void ft_sort_stack2(t_stacks *main_struct);
void ft_sort_stack3(t_stacks *main_struct);
int ft_check_sort_ps(t_stacks    main_struct);
int is_ready_sort(t_stacks *main_struct);
void ft_print_command(t_stacks *main_struct, char *command);

/*----------------------------has_gap----------------------------*/

int	ft_count_has_gap(t_stacks *main_struct, int item, int len_a);
void ft_find_pos_after_gap(t_stacks *main_struct, int item,  int *num_item, int *is_not_found);
void ft_find_gap(t_stacks *main_struct, int item,  int *num_item, int *is_not_found);

/*-------------------------count_actions-------------------------*/

int is_has_gap(t_stacks main_struct);
int ft_count_no_gap(t_stacks *main_struct, int item, int len_a);
int ft_count_actions_in_a(t_stacks *main_struct, int item, int len_a);
int ft_count_actions_in_b(t_lis *b, int item, int len_b);
int ft_check_quantity_throw(t_stacks main_struct);

/*-----------------------------moves------------------------------*/

int	ft_count_moves(int num_item, int len_stack);
void ft_move_common(t_stacks *main_struct, int num_item_a, int num_item_b);
void ft_rotate(t_stacks *main_struct, int num_item, int len_stack, char which_stack);
void ft_rotate_double(t_stacks *main_struct, int *num_item_a, int *num_item_b);

/*----------------------------throwing-----------------------------*/

int	ft_find_poss_for_less_throws_a(t_stacks main_struct);
int	ft_find_poss_for_less_throws_b(t_stacks main_struct);
void ft_make_throws(t_stacks *main_struct);
void ft_throwing(t_stacks *main_struct);

#endif
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
# define SA sa(main_struct)
# define SB sb(main_struct)
# define SS ss(main_struct)
# define PB pb(main_struct)
# define PA pa(main_struct)
# define RA ra(main_struct)
# define RB rb(main_struct)
# define RR rr(main_struct)
# define RRA rra(main_struct)
# define RRB rrb(main_struct)
# define RRR rrr(main_struct)

# define BUFF_SIZE 2
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "libft/libft.h"

typedef struct              s_lis
{
    int                    	num;
    struct        s_lis    	*next;
    struct        s_lis    	*prev;
	int 					common_and_pos_a_b[3];
}                           t_lis;

typedef struct              s_stacks
{
    t_lis                   *a;
    t_lis                   *b;
    int                     is_first;
    int 					a_len;
    int 					b_len;
	int 					min_actions;
	int 					flag_stay_in_first;
}                           t_stacks;

/*-----------------------------main-----------------------------*/

int		get_next_line(const int fd, char **line);

/*--------------------------auxiliary--------------------------*/

int		ft_length_list(const t_lis *start);
int 	is_correct_input(char **str);
void	ft_list_clear(t_lis **begin_list);

int 	is_need_parsing(char **argv);
int		is_int(char **tmp);
int		ft_atoi_for_over(const char *str);

/*----------------------------moves----------------------------*/

void    sa(t_stacks	*main_struct);
void    sb(t_stacks	*main_struct);
void    ss(t_stacks *stacks);

void    pb(t_stacks *stacks);
void    pa(t_stacks *stacks);

void	ra(t_stacks *stacks);
void	rb(t_stacks *stacks);
void	rr(t_stacks *stacks);

void	rra(t_stacks *stacks);
void	rrb(t_stacks *stacks);
void	rrr(t_stacks *stacks);

/*--------------------------validation--------------------------*/

char	**ft_shift_matrix(char **argv);
int	    ft_parse(char **argv, t_stacks    *main_struct);
int		ft_parse_and_fill(t_stacks    *main_struct, int argc, char **argv);


void    ft_check_dup(int *array, int len, int i, int j);
void    ft_check_duplicates(t_stacks    *main_struct);
t_lis    *ft_create_stack(char **tmp);



/*---------------------------push_swap---------------------------*/

int	ft_count_moves(int num_item, int len_stack);
int ft_count_no_gap(t_stacks *main_struct, int item, int len_a);
int is_has_gap(t_stacks main_struct);

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
void ft_move_no_gap(t_stacks *main_struct, int len_a, int item);
void ft_move_common(t_stacks *main_struct, int num_item, int len_stack, char which_stack);
void ft_move_b(t_stacks *main_struct, int item_b, int len_b);

/*----------------------------throwing-----------------------------*/

int	ft_find_poss_for_less_throws_a(t_stacks main_struct);
int	ft_find_poss_for_less_throws_b(t_stacks main_struct);
void ft_make_throws(t_stacks *main_struct);
void ft_throwing(t_stacks *main_struct);

#endif
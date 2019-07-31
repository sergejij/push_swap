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

# include <stdio.h>
# include "./libft/libft.h"

# define BUFF_SIZE 2
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include "libft/libft.h"
//# include <fcntl.h>


typedef struct              s_lis
{
    int                    	num;
    struct        s_lis    	*next;
    struct        s_lis    	*prev;
}                           t_lis;

typedef struct              s_stacks
{
    t_lis                   *a;
    t_lis                   *b;
    int                     median;
    int 					a_len;
    int 					b_len;
    t_lis					*sorted;
}                           t_stacks;

int		get_next_line(const int fb, char **line);

/*-----------------------------main-----------------------------*/

int		get_next_line(const int fd, char **line);

/*--------------------------auxiliary--------------------------*/

int 	is_correct_input(char **str);
void    ft_print_list(t_lis *start);
void	ft_list_clear(t_lis **begin_list);

int 	is_need_parsing(char **argv);
int		is_int(char **tmp);
int		ft_atoi_for_over(const char *str);
int	ft_length_list(const t_lis *start);
/*void 	ft_bubble_sort_list(t_stacks main_struct);
void 	ft_bubble_sort_list_2(t_stacks main_struct, t_lis *begin);
void	ft_bubble_sort_list(t_stacks main_struct);
void	ft_check_duplicates(t_stacks main_struct);*/

/*int     ft_len_stack_a(t_stacks stacks);
int     ft_len_stack_b(t_stacks stacks);*/

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


int    ft_sort_array(int *array, int len);
void    ft_check_duplicates(t_stacks    *main_struct);
t_lis    *ft_create_stack(char **tmp);


#endif
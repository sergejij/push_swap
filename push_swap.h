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

#include <stdio.h>
#include <stdlib.h>
# include "./libft/libft.h"

typedef struct              s_lis
{
    int                     num;
    struct        s_lis    *next;
    struct        s_lis    *prev;
}                           t_lis;

typedef struct              s_stacks
{
    t_lis                     *a;
    t_lis                     *b;
}                           t_stacks;

/*-----------------------------main-----------------------------*/

t_lis	*ft_create_stack(int argc, char **argv);

/*--------------------------auxiliary--------------------------*/

int 	is_need_parsing(char **argv);
int 	is_correct_input(char **str);
void    ft_print_list(t_lis *start);
int		ft_length_list(const t_lis *start);
void	ft_list_clear(t_lis **begin_list);

/*----------------------------moves----------------------------*/

void    sa(t_stacks	*main_struct);
/*void    sb(t_stacks *stacks);
void    ss(t_stacks *stacks);*/
/*int     ft_len_stack_a(t_stacks stacks);
int     ft_len_stack_b(t_stacks stacks);*/

/*--------------------------validation--------------------------*/

char	**ft_shift_matrix(char **argv, int argc);
int		ft_parse_and_fill(t_stacks    *main_struct, int argc, char **argv);

#endif
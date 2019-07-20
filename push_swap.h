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

typedef struct              s_stacks
{
    int                     stack_a[100];
    int                     stack_b[100];
}                           t_stacks;

typedef struct              s_list
{
    int                     num;
    struct        s_list    *next;
    struct        s_list    *prev;
}                           t_list;

/*--------------------------moves--------------------------*/

int     ft_len_stack_a(t_stacks stacks);
int     ft_len_stack_b(t_stacks stacks);

void    sa(t_stacks *stacks);
void    sb(t_stacks *stacks);
void    ss(t_stacks *stacks);
#endif
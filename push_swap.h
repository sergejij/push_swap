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

/*--------------------------moves--------------------------*/

int     ft_len_stack_a(t_stacks stacks);
int     ft_len_stack_b(t_stacks stacks);

void    sa(t_stacks *stacks);
void    sb(t_stacks *stacks);
void    ss(t_stacks *stacks);
#endif
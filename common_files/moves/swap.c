/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubartemi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 13:54:00 by ubartemi          #+#    #+#             */
/*   Updated: 2019/08/19 13:56:46 by ubartemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

void	sa(t_stacks *main_struct)
{
	t_lis	*begin;
	int		tmp;

	tmp = 0;
	if (main_struct->a_len < 2)
		return ;
	begin = main_struct->a;
	if (begin->next && main_struct->a_len > 1)
	{
		tmp = begin->num;
		begin->num = begin->next->num;
		begin->next->num = tmp;
	}
}

void	sb(t_stacks *main_struct)
{
	t_lis	*begin;
	int		tmp;

	tmp = 0;
	if (main_struct->b_len < 2)
		return ;
	begin = main_struct->b;
	if (begin->next)
	{
		tmp = begin->num;
		begin->num = begin->next->num;
		begin->next->num = tmp;
	}
}

void	ss(t_stacks *main_struct)
{
	sa(&(*main_struct));
	sb(&(*main_struct));
}

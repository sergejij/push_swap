/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubartemi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 13:53:10 by ubartemi          #+#    #+#             */
/*   Updated: 2019/08/19 13:53:30 by ubartemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

void	ra(t_stacks *stacks)
{
	t_lis *begin;
	t_lis *second;

	if (stacks->a && stacks->a->next)
	{
		begin = stacks->a;
		second = begin->next;
		while (stacks->a->next)
			stacks->a = stacks->a->next;
		begin->prev = stacks->a;
		stacks->a->next = begin;
		begin->next = NULL;
		begin = second;
		begin->prev = NULL;
		stacks->a = begin;
	}
}

void	rb(t_stacks *stacks)
{
	t_lis *begin;
	t_lis *second;

	if (stacks->b && stacks->b->next)
	{
		begin = stacks->b;
		second = begin->next;
		while (stacks->b->next)
			stacks->b = stacks->b->next;
		begin->prev = stacks->b;
		stacks->b->next = begin;
		begin->next = NULL;
		begin = second;
		begin->prev = NULL;
		stacks->b = begin;
	}
}

void	rr(t_stacks *stacks)
{
	ra(stacks);
	rb(stacks);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubartemi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 13:51:20 by ubartemi          #+#    #+#             */
/*   Updated: 2019/08/19 13:52:17 by ubartemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

void	pb(t_stacks *stacks)
{
	t_lis *tmp;

	if (stacks->a)
	{
		tmp = stacks->b;
		stacks->b = stacks->a;
		if (stacks->a->next)
		{
			stacks->a = stacks->a->next;
			stacks->a->prev = NULL;
		}
		else
			stacks->a = NULL;
		if (tmp)
		{
			stacks->b->next = tmp;
			tmp->prev = stacks->b;
		}
		else
			stacks->b->next = NULL;
	}
}

void	pa(t_stacks *stacks)
{
	t_lis *tmp;

	if (stacks->b)
	{
		tmp = stacks->a;
		stacks->a = stacks->b;
		if (stacks->b->next)
		{
			stacks->b = stacks->b->next;
			stacks->b->prev = NULL;
		}
		else
			stacks->b = NULL;
		if (tmp)
		{
			stacks->a->next = tmp;
			tmp->prev = stacks->a;
		}
		else
			stacks->a->next = NULL;
	}
}

#include "../push_swap.h"

void    pb(t_stacks *stacks)
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
	}//взять значение первого эл-та в а и поместить в верх b
}

void    pa(t_stacks *stacks)
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
	}//взять значение первого эл-та в а и поместить в верх b
}
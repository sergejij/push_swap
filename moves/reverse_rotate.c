#include "../push_swap.h"

void	rra(t_stacks *stacks)
{
	t_lis *begin;
	t_lis *penultimate;

	if (stacks->a && stacks->a->next)
	{
		begin = stacks->a;
		while (stacks->a->next)
			stacks->a = stacks->a->next;
		penultimate = stacks->a->prev;
		stacks->a->next = begin;
		begin->prev = stacks->a;
		stacks->a->prev = NULL;
		penultimate->next = NULL;
	}
} // последний становится первым

void	rrb(t_stacks *stacks)
{
	t_lis *begin;
	t_lis *penultimate;

	if (stacks->b && stacks->b->next)
	{
		begin = stacks->b;
		while (stacks->b->next)
			stacks->b = stacks->b->next;
		penultimate = stacks->b->prev;
		stacks->b->next = begin;
		begin->prev = stacks->b;
		stacks->b->prev = NULL;
		penultimate->next = NULL;
	}
}

void	rrr(t_stacks *stacks)
{
	rra(stacks);
	rrb(stacks);
}
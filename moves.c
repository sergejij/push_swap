#include "push_swap.h"

void    sa(t_stacks	*main_struct)
{
	t_lis *begin;
	int tmp;

	tmp = 0;
	begin = main_struct->a;
	if (begin->next)
	{
		tmp = begin->num;
		begin->num = begin->next->num;
		begin->next->num = tmp;
	}
}
void    sb(t_stacks	*main_struct)
{
	t_lis *begin;
	int tmp;

	tmp = 0;
	begin = main_struct->b;
	if (begin->next)
	{
		tmp = begin->num;
		begin->num = begin->next->num;
		begin->next->num = tmp;
	}
}

void    ss(t_stacks	*main_struct)
{
	sa(&(*main_struct));
	//ft_print_list(main_struct.a);
	sb(&(*main_struct));
}

void    pb(t_stacks *stacks)
{
	t_lis *tmp;
	if (stacks->a)
	{
		tmp = stacks->b;
		stacks->b = (stacks->a);
		if ((stacks->a)->next)
		{
			stacks->a = (stacks->a)->next;
			(stacks->a)->prev = NULL;
		}
		else
			stacks->a = NULL;
		if (tmp)
			stacks->b->next = tmp;
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
		stacks->a = (stacks->b);
		if ((stacks->b)->next)
		{
			stacks->b = (stacks->b)->next;
			(stacks->b)->prev = NULL;
		}
		else
			stacks->b = NULL;
		if (tmp)
			stacks->a->next = tmp;
		else
			stacks->a->next = NULL;
	}//взять значение первого эл-та в b и поместить в верх a
}

void	ra(t_stacks *stacks)
{
	t_lis *begin;
	t_lis *second;

	begin = stacks->a;
	second = begin->next;
	while (stacks->a->next)
		stacks->a = stacks->a->next;
	begin->prev = stacks->a;
	stacks->a->next = begin;
	begin->next = NULL;
	begin = second;
	begin->prev = NULL;
} // сдвинуть каждый эл-т стэка на 1, Первый станет последним
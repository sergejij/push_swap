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
	if ((stacks->a)->next)
	{
		stacks->b = (stacks->a);
		stacks->a = (stacks->a)->next;
		stacks->b->next = NULL;
		(stacks->a)->prev = NULL;
	}//взять значение первого эл-та в а и поместить в верх б
}

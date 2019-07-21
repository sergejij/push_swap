#include "push_swap.h"

void    sa(t_stacks	*main_struct)
{
	t_lis *begin;
	int tmp;

	begin = main_struct->a;
	if (begin->next)
	{
		tmp = begin->num;
		begin->num = begin->next->num;
		begin->next->num = tmp;
	}
}
/*
void    sb(t_stacks *stacks)
{
    char tmp;

    if (ft_len_stack_b(*stacks) > 1)
    {
        tmp = stacks->stack_b[0];
        stacks->stack_b[0] = stacks->stack_b[1];
        stacks->stack_b[1] = tmp;
    }
}

void    ss(t_stacks *stacks)
{
    sa(stacks);
    sb(stacks);
}*/
/*
void    pb(t_stacks *stacks)
{
    if (ft_len_stack_a(*stacks) > 0)
    {
        if (ft_len_stack_b(*stacks) == 0)
            stacks->stack_a[0] = stacks->stack_b[0];
        else
            while ( )
            {

            }
    }
    char tmp;

    if (ft_len_stack_a(*stacks) > 1)
    {
        tmp = stacks->stack_a[0];
        stacks->stack_a[0] = stacks->stack_a[1];
        stacks->stack_a[1] = tmp;
    }
}
*/

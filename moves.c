//
// Created by Ulrick Bartemius on 2019-07-18.
//
#include "push_swap.h"

int  ft_len_stack_a(t_stacks stacks)
{
    int i;

    i = 0;
    while ((stacks.stack_a)[i])
        i++;
    return (i);
}

int  ft_len_stack_b(t_stacks stacks)
{
    int i;

    i = 0;
    while ((stacks.stack_b)[i])
        i++;
    return (i);
}

void    sa(t_stacks *stacks)
{
    char tmp;

    if (ft_len_stack_a(*stacks) > 1)
    {
        tmp = stacks->stack_a[0];
        stacks->stack_a[0] = stacks->stack_a[1];
        stacks->stack_a[1] = tmp;
    }
}

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
}
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

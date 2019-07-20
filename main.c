#include <stdio.h>
#include <stdlib.h>
#include "push_swap.h"

void    ft_printf_list(t_list *start)
{
    t_list *begin;

    begin = start;
    while (start)
    {
        printf("%d ", start->num);
        start = start->next;
    }
}

t_list    *ft_create_stack(int argc, char **argv)
{
    int i;
    t_list *begin;
    t_list *stack;
    t_list *new;

    i = 1;
    stack = (t_list *)malloc(sizeof(t_list));
    begin = stack;
    stack->num = atoi(argv[i]);
    stack->next = NULL;
    stack->prev = NULL;
    while (i < argc)
    {
        new = (t_list *)malloc(sizeof(t_list));
        stack->next = new;
        new->next = NULL;
        new->prev = stack;
        stack = new;
        i++;
        stack->num = atoi(argv[i]);
    }
    return (begin);
}


int     main(int argc, char **argv)
{
    t_stacks struct_m;
    t_list  *a;
    t_list  *b;
    if (argc < 2)
        return (0);
    struct_m.a = ft_create_stack(argc - 1, argv);
    b = malloc(sizeof(t_list));
    ft_printf_list(struct_m.a);
    return 0;
}
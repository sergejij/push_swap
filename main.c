#include <stdio.h>
#include <stdlib.h>
#include "push_swap.h"



void    ft_filling_a(int argc, char **argv, t_stacks *stacks)
{
    int i;

    i = 0;

    while (i + 1 < argc)
    {
        (stacks->stack_a)[i] = atoi(argv[i + 1]);
        i++;
    }
    i = 0;
    while (i + 1 < argc)
        printf("%d ", (stacks->stack_a)[i++]);
}

int     main(int argc, char **argv) {
    int i = 0;
    t_stacks stacks;
    if (argc < 2)
        return (0);
    ft_filling_a(argc, argv, &stacks);
    sa(&stacks);
    printf("\n");
    while (i + 1 < argc)
        printf("%d ", (stacks.stack_a)[i++]);
    return 0;
}
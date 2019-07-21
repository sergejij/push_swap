#include <stdio.h>
#include <stdlib.h>
#include "push_swap.h"

int is_need_parsing(char **argv)
{
    int i;

    i = 0;
    while (argv[1][i])
    {
        if (argv[1][i] == ' ')
            return (1);
        i++;
    }
    return (0);
}

void    ft_printf_list(t_lis *start)
{
    t_lis *begin;

    begin = start;
    while (start)
    {
        printf("%d ", start->num);
        start = start->next;
    }
}

t_lis    *ft_create_stack(int argc, char **argv)
{
    int     i;
    t_lis *begin;
    t_lis *stack;
    t_lis *new;

    i = 1;
    stack = (t_lis *)malloc(sizeof(t_lis));
    begin = stack;
    stack->num = ft_atoi(argv[i]);
    stack->next = NULL;
    stack->prev = NULL;
    while (i < argc)
    {
        new = (t_lis *)malloc(sizeof(t_lis));
        stack->next = new;
        new->next = NULL;
        new->prev = stack;
        stack = new;
        i++;
        stack->num = ft_atoi(argv[i]);
    }
    return (begin);
}
/*char    **ft_parse(char *str)
{
    char    **parsed_str;


}*/

/*t_lis    *ft_parse_and_create_stack(char **argv)
{
    int     i;
    t_lis *begin;
    t_lis *stack;
    t_lis *new;
    char *current_number;

    i = 0;
    stack = (t_lis *)malloc(sizeof(t_lis));
    begin = stack;
    while (argv[1][i + 1])
    {
        stack->num = atoi(&argv[1][i]);
        new = malloc(sizeof(t_lis));
        stack->next = new;
        new->prev = stack;
        new->next = NULL;
        stack = new;
        i++;
    }
    stack->num = atoi(&argv[1][i]);
    return (begin);
}*/

int       main(int argc, char **argv)
{
    t_stacks    main_struct;
    t_lis      *a;
    t_lis      *b;

    if (argc < 2)
        return (0);
    //if (argc == 2 && is_need_parsing(argv))
      //  main_struct.a = ft_parse_and_create_stack(argv);
    //else
        main_struct.a = ft_create_stack(argc - 1, argv);
    b = malloc(sizeof(t_lis));
    ft_printf_list(main_struct.a);
    return 0;
}
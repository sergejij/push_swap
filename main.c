#include "push_swap.h"

t_lis    *ft_create_stack(int argc, char **argv)
{
    int     i;
    t_lis *begin;
    t_lis *stack;
    t_lis *new;

    i = 0;
	stack = malloc(sizeof(t_lis));
	stack->next = NULL;
	stack->prev = NULL;
	begin = stack;
    while (argv[i + 1])
    {
		stack->num = ft_atoi(argv[i]);
		new = malloc(sizeof(t_lis));
		stack->next = new;
		new->prev = stack;
		new->next = NULL;
		stack = new;
		i++;
    }
	stack->num = ft_atoi(argv[i]);
    return (begin);
}

int       main(int argc, char **argv)
{
    t_stacks    main_struct;
    t_lis       *b;

    if (argc < 2)
        return (0);

    if (!(ft_parse_and_fill(&main_struct, argc, argv)))
    	return (0);
	ft_print_list(main_struct.a);
	printf("\n");
    sa(&main_struct);
    ft_print_list(main_struct.a);
	ft_list_clear(&main_struct.a);
    return 0;
}

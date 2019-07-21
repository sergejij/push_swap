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
    start = begin;
}

t_lis    *ft_create_stack(int argc, char **argv)
{
    int     i;
    t_lis *begin;
    t_lis *stack;
    t_lis *new;

    i = 0;
	stack = (t_lis *)malloc(sizeof(t_lis));
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

char **ft_make_for_parse(char **argv, int argc)
{
	char **for_parse;
	int i;

	i = 1;
	for_parse = (char**)malloc(sizeof(char*) * (argc));
	while (argv[i])
	{
		for_parse[i - 1] = (char*)malloc(sizeof(char) * (ft_strlen(argv[i] + 1)));
		for_parse[i - 1] = argv[i];
		i++;
	}
	for_parse[i - 1] = NULL;
	return (for_parse);
}

int 	is_correct_input(char **str)
{
	int i;
	int j;

	j = 0;
	i = 0;
	while (str[i])
	{
		while (str[i][j])
		{
			if (str[i][j] < 48 || str[i][j] > 57)
			{
				printf("Error");
				return (0);
			}
			j++;
		}
		j = 0;
		i++;
	}
	return (1);
}

void	ft_parse_and_fill(t_stacks    *main_struct, int argc, char **argv)
{
	char        **tmp;
	t_lis       *a;

	if (argc == 2 && is_need_parsing(argv))
	{
		tmp = ft_strsplit(argv[1], ' ');
		if (is_correct_input(tmp))
			(*main_struct).a = ft_create_stack(ft_count_word(argv[1], ' '), tmp);
	}
	else
	{
		tmp = ft_make_for_parse(argv, argc);
		if (is_correct_input(tmp))
			(*main_struct).a = ft_create_stack(argc, tmp);
	}
	ft_printf_list((*main_struct).a);
}

int       main(int argc, char **argv)
{
    t_stacks    main_struct;
    t_lis       *b;

    if (argc < 2)
        return (0);
    ft_parse_and_fill(&main_struct, argc, argv);

    b = malloc(sizeof(t_lis));
    ft_printf_list(main_struct.a);
    return 0;
}
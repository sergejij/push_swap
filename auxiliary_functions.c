//
// Created by Ulrick Bartemius on 2019-07-21.
//
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
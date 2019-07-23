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
			if ((str[i][j] < 48 || str[i][j] > 57) && (j != 0 || str[i][0] != '-'))
				return (0);
			j++;
		}
		j = 0;
		i++;
	}
	return (1);
}

/*
int	ft_length_list(const t_lis *start)
{
	int counter;

	counter = 0;
	while (start)
	{
		start = start->next;
		counter++;
	}
	return (counter);
}*/

void    ft_print_list(t_lis *start)
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

void	ft_list_clear(t_lis **begin_list)
{
	t_lis	*tmp;
	t_lis	*list;

	list = *begin_list;
	tmp = NULL;
	while (list)
	{
		if (list->next)
		{
			tmp = list->next;
			list->prev = NULL;
		}
		else
			tmp = NULL;
		free(list);
		list = tmp;
	}
}

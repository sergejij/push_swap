#include "push_swap.h"

void ft_bubble_sort_list_2(t_stacks *main_struct, t_lis *begin)
{
	t_lis	*tmp;
	int 	tmp_int;

	tmp = begin;
	while (tmp && tmp->next)
	{
		if (tmp->num > tmp->next->num)
		{
			tmp_int = tmp->num;
			tmp->num = tmp->next->num;
			tmp->next->num = tmp_int;
		}
		else if (tmp->num == tmp->next->num)
		{
			ft_putstr_fd("Error\n", 2);
			exit (1);
		}
		tmp = tmp->next;
	}
}

void ft_bubble_sort_list(t_stacks *main_struct)
{
	t_lis	*begin;

	begin = main_struct->a;
	while (main_struct->a)
	{
		ft_bubble_sort_list_2(main_struct, begin);
		main_struct->a = main_struct->a->next;
	}
	main_struct->a = begin;
}

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

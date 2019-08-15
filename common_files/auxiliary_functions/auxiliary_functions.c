#include "../checker.h"

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
			if ((str[i][j] < 48 || str[i][j] > 57)
			&& (j != 0 || str[i][0] != '-') && (j != 0 || str[i][0] != '+'))
				return (0);
			j++;
		}
		j = 0;
		i++;
	}
	return (1);
}

int	ft_length_list(const t_lis *start)
{
	int counter;

	counter = 0;
	if (!start->next)
		return (1);
	while (start && start->next)
	{
		start = start->next;
		counter++;
	}
	return (++counter);
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

void ft_error()
{
	ft_putstr_fd("Error\n", 2);
	exit (1);
}

void ft_print_stacks(t_stacks *main_struct)
{
	t_lis *begin_a;
	t_lis *begin_b;

	begin_a = main_struct->a;
	begin_b = main_struct->b;
	ft_putstr("Stack A:");
	while (main_struct->a)
	{
		ft_putchar(' ');
		ft_putnbr(main_struct->a->num);
		main_struct->a = main_struct->a->next;
	}
	ft_putchar('\n');
	ft_putstr("Stack B:");
	while (main_struct->b)
	{
		ft_putchar(' ');
		ft_putnbr(main_struct->b->num);
		main_struct->b = main_struct->b->next;
	}
	ft_putchar('\n');
	main_struct->a = begin_a;
	main_struct->b = begin_b;
}

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
			if (((str[i][j] < 48 || str[i][j] > 57)
			&& (j != 0 || str[i][0] != '-') && (j != 0 || str[i][0] != '+'))
			/*|| (str[1][0] == '-' && str[1][1] == 'v')*/)
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

void ft_print_stacks(t_lis *a, t_lis *b, char *command)
{
	ft_putstr("Execute the command - ");
	ft_putstr(command);
	ft_putchar('\n');
	ft_putstr("\033[33;1;4mStack A:\033[0m");
	while (a)
	{
		ft_putchar(' ');
		ft_putnbr(a->num);
		a = a->next;
	}
	ft_putchar('\n');
	ft_putstr("\033[34;1;4mStack B:\033[0m");
	while (b)
	{
		ft_putchar(' ');
		ft_putnbr(b->num);
		b = b->next;
	}
	ft_putstr("\n---------------------------------------------\n");
}

#include "push_swap.h"

int		ft_atoi_for_over(const char *str)
{
	int				counter;
	int				result;
	int				sign;

	sign = 1;
	result = 0;
	counter = 0;
	while ((str[counter] > 7 && str[counter] < 14) || str[counter] == ' ')
		counter++;
	if (str[counter] == '-')
	{
		sign = -1;
		counter++;

	}
	while (str[counter] > '\0')
	{
		if (result * 10 / 10 != result && sign == 1)
			return (-1);
		else if (result * 10 / 10 != result && sign == -1)
			return (0);
		result = (result * 10) + (str[counter++] - '0');
	}
	return (result * sign);
}

t_lis    *ft_create_stack(char **tmp)
{
	int     i;
	t_lis *begin;
	t_lis *stack;
	t_lis *new;

	i = 0;
	stack = malloc(sizeof(t_lis));
	stack->next = NULL;
	stack->prev = NULL;
	stack->len = 0;
	begin = stack;
	while (tmp[i + 1])
	{
		stack->num = ft_atoi(tmp[i++]);
		new = malloc(sizeof(t_lis));
		stack->next = new;
		new->prev = stack;
		new->next = NULL;
		stack = new;
	}
	begin->len = i + 1;
	stack->num = ft_atoi(tmp[i]);
	return (begin);
}

int is_int(char **tmp)
{
	int i;
	long long cmp;

	cmp = 0;
	i = 0;
	while (tmp[i])
	{
		if (ft_strlen(tmp[i]) >= 10)
		{
			if (tmp[i][0] == '-')
			{
				cmp = ft_atoi_for_over(tmp[i]);
				if (cmp == 0 || ft_strcmp("-2147483649", tmp[i]) == 0)
					return (0);
			}
			else
			{
				cmp = ft_atoi_for_over(tmp[i]);
				if (cmp < 0)
					return (0);
			}
		}
		i++;
	}
	return (1);
}

char **ft_shift_matrix(char **argv)
{
	int i;

	i = 1;
	while (argv[i])
	{
		argv[i - 1] = argv[i];
		i++;
	}
	argv[i - 1] = NULL;
	return (argv);
}

int	ft_parse(char **argv, t_stacks    *main_struct)
{
	int i;
	char **tmp;

	i = 0;
	tmp = ft_strsplit(argv[1], ' ');
	if (is_correct_input(tmp) && is_int(tmp))
		(*main_struct).a = ft_create_stack(tmp);
	else
	{
		while (tmp[i])
			free(tmp[i++]);
		free(tmp);
		return (0);
	}
	while (tmp[i])
		free(tmp[i++]);
	free(tmp);
	return (1);
}

int	ft_parse_and_fill(t_stacks    *main_struct, int argc, char **argv)
{
	if (argc == 2 && is_need_parsing(argv))
	{
		if (!(ft_parse(argv, main_struct)))
			return (0);
	}
	else
	{
		argv = ft_shift_matrix(argv);
		if (is_correct_input(argv) && is_int(argv))
			(*main_struct).a = ft_create_stack(argv);
		else
			return (0);

	}
	return (1);
}
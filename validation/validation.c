#include "../push_swap.h"


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
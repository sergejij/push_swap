#include "../checker.h"

char **ft_shift_matrix(char **argv, int argc, char **tmp)
{
	int i;

	i = 1;
	if (!(tmp = (char**)malloc(sizeof(char*) * argc)))
	{
		free(tmp);
		exit (1);
	}
	while (argv[i])
	{
		tmp[i - 1] = (char*)malloc(sizeof(char) + ft_strlen(argv[i]));
		ft_strcpy(tmp[i - 1], argv[i]);
		tmp[i - 1][ft_strlen(argv[i])] = '\0';
		i++;
	}
	tmp[i - 1] = NULL;
	return (tmp);
}

int	ft_parse(char **argv, t_stacks    *main_struct)
{
	char **tmp;

	tmp = ft_strsplit(argv[1], ' ');
	if (is_correct_input(tmp) && is_int(tmp))
		(*main_struct).a = ft_create_stack(tmp);
	else
	{
		ft_free_matrix(tmp);
		return (0);
	}
	ft_free_matrix(tmp);
	return (1);
}

int	ft_parse_and_fill(t_stacks    *main_struct, int argc, char **argv)
{
	char **tmp;

	tmp = NULL;
	if (argc == 2 && is_need_parsing(argv))
	{
		if (!(ft_parse(argv, main_struct)))
			return (0);
	}
	else
	{
		tmp = ft_shift_matrix(argv, argc, tmp);
		if (is_correct_input(tmp) && is_int(tmp))
			(*main_struct).a = ft_create_stack(tmp);
		else
		{
			ft_free_matrix(tmp);
			return (0);
		}
		ft_free_matrix(tmp);
	}
	return (1);
}
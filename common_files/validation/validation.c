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


int	ft_parse_fill(t_stacks *m_struct, t_flags *f_struct, int argc,
					 char **argv)
{
	char **tmp;

	tmp = NULL;
	ft_parse_flags(f_struct, argv);
	if (argc <= f_struct->sep_f + 1)
		ft_error();
	if (argc == f_struct->sep_f + 2 && is_need_parsing(argv, *f_struct))
	{
		if (!(ft_parse(argv + f_struct->sep_f, m_struct)))
			return (0);
	}
	else
	{
		tmp = (f_struct->sep_f) ? ft_shift_matrix(argv + f_struct->sep_f,
				argc - 1, tmp) : ft_shift_matrix(argv, argc, tmp);
		if (is_correct_input(tmp) && is_int(tmp))
			(*m_struct).a = ft_create_stack(tmp);
		else
		{
			ft_free_matrix(tmp);
			return (0);
		}
		ft_free_matrix(tmp);
	}
	return (1);
}
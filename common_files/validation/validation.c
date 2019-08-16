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

void ft_check_flags(t_stacks *main_struct)
{
	if (main_struct->debug_mode > 1
	|| main_struct->count_mode > 1
	|| main_struct->file_mode > 1)
		ft_error();
}

void ft_parse_flags(t_stacks    *main_struct,char **argv)
{
	int i;
	int j;

	i = 1;
	while (i <= 3 && argv[i])
	{
		if (argv[i][0] == '-')
		{
			j = 1;
			while (argv[i][j])
			{
				if (argv[i][j] == 'v')
				{
					main_struct->debug_mode += 1;
					main_struct->num_sep_flags = i;
				}
				else if (argv[i][j] == 'c')
				{
					main_struct->count_mode += 1;
					main_struct->num_sep_flags = i;
				}
				else if (argv[i][j] == 'f')
				{
					main_struct->file_mode += 1;
					main_struct->num_sep_flags = i;
				}
				else if (argv[i][j] < 48 | argv[i][j] > 57)
					ft_error();
				j++;
			}
		}
		i++;
	}
	ft_check_flags(main_struct);
}

int	ft_parse_and_fill(t_stacks    *main_struct, int argc, char **argv)
{
	char **tmp;

	tmp = NULL;
	ft_parse_flags(main_struct, argv);
	/*if (argc == 2 && is_need_parsing(argv, *main_struct))
	{
		if (!(ft_parse(argv, main_struct)))
			return (0);
	}*/
	if (argc == main_struct->num_sep_flags + 2 && is_need_parsing(argv, *main_struct))
	{
		if (!(ft_parse(argv + main_struct->num_sep_flags, main_struct)))
			return (0);
	}
	else
	{
		if (main_struct->num_sep_flags)
			tmp = ft_shift_matrix(argv + main_struct->num_sep_flags + 1, argc - 1, tmp);
		else
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
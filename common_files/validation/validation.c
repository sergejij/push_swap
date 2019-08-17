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

void ft_check_flags(t_flags *flags_struct)
{
	if (flags_struct->debug_mode > 1
	|| flags_struct->count_mode > 1
	|| flags_struct->file_mode > 1)
		ft_error();
}

void ft_parse_flags_fill(t_flags *flags_struct, char **argv, char flag, int i)
{
	if (flag == 'v')
	{
		flags_struct->debug_mode += 1;
		flags_struct->num_sep_flags = flags_struct->num_sep_flags == 0
									  ? i : flags_struct->num_sep_flags;
	}
	else if (flag == 'c')
	{
		flags_struct->count_mode += 1;
		flags_struct->num_sep_flags = flags_struct->num_sep_flags == 0
									  ? i : flags_struct->num_sep_flags;
	}
	else if (flag == 'f')
	{
		flags_struct->file_mode += 1;
		flags_struct->num_sep_flags = i + 1;
		flags_struct->file_name = argv[i + 1];
	}
}

void ft_parse_flags(t_flags *flags_struct, char **argv)
{
	int i;
	int j;

	i = 1;
	while (i <= 3 && argv[i])
	{
		if (argv[i][0] == '-')
		{
			j = 1;
			while (j <= 3 &&argv[i][j])
			{
				if (argv[i][j] == 'v')
					ft_parse_flags_fill(flags_struct, argv, argv[i][j], i);
				else if (argv[i][j] == 'c')
					ft_parse_flags_fill(flags_struct, argv, argv[i][j], i);
				else if (argv[i][j] == 'f')
					ft_parse_flags_fill(flags_struct, argv, argv[i][j], i);
				else if ((argv[i][j] < 48 || argv[i][j] > 57)
				&& argv[i][j] != 32 && argv[i][j] != '-')
					ft_error();
				j++;
			}
		}
		i++;
	}
	ft_check_flags(flags_struct);
}

int	ft_parse_and_fill(t_stacks    *main_struct, t_flags    *flags_struct, int argc, char **argv)
{
	char **tmp;

	tmp = NULL;
	ft_parse_flags(flags_struct, argv);
	if (argc <= flags_struct->num_sep_flags + 1)
		ft_error();
	if (argc == flags_struct->num_sep_flags + 2 && is_need_parsing(argv, *flags_struct))
	{
		if (!(ft_parse(argv + flags_struct->num_sep_flags, main_struct)))
			return (0);
	}
	else
	{
		tmp = (flags_struct->num_sep_flags) ? ft_shift_matrix(argv + flags_struct->num_sep_flags, argc - 1, tmp) :
				ft_shift_matrix(argv, argc, tmp);
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
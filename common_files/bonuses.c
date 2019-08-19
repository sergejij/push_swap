#include "checker.h"

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

void ft_write_file(t_flags *flags_struct, t_stacks *main_struct)
{
	if ((main_struct->fd = open(flags_struct->file_name,
								O_CREAT | O_RDWR | O_APPEND | O_TRUNC, S_IWRITE | S_IREAD)) == -1)
	{
		ft_putstr_fd("Open/create file error\n", 2);
		ft_list_clear(&main_struct->a);
		ft_list_clear(&main_struct->b);
		exit (1);
	}
}
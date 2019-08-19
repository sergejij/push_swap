#include "../push_swap_files/push_swap.h"

void	ft_apply_commands(t_stacks *main_struct, char *command)
{
	(main_struct->counter)++;
	if (!ft_strcmp("sa", command))
		SA;
	else if (!ft_strcmp("sb", command))
		SB;
	else if (!ft_strcmp("ss", command))
		SS;
	else if (!ft_strcmp("pb", command))
		PB;
	else if (!ft_strcmp("pa", command))
		PA;
	else if (!ft_strcmp("ra", command))
		RA;
	else if (!ft_strcmp("rb", command))
		RB;
	else if (!ft_strcmp("rr", command))
		RR;
	else if (!ft_strcmp("rra", command))
		RRA;
	else if (!ft_strcmp("rrb", command))
		RRB;
	else if (!ft_strcmp("rrr", command))
		RRR;
	else
		ft_error();
}

void ft_check_sort(t_stacks    *main_struct, t_flags flags_struct)
{
    t_lis *begin;

    if (!main_struct->a)
        return ;
    begin = main_struct->a;
    while (main_struct->a && main_struct->a->next)
    {
        if ((main_struct->a->num > main_struct->a->next->num) || main_struct->b)
        {
            ft_putstr("\033[31;1mKO\033[0m\n");
            exit (1);
        }
        main_struct->a = main_struct->a->next;
    }
    main_struct->a = begin;
    ft_putstr("\033[32;1mOK\033[0m\n");
	if (flags_struct.count_mode)
	{
		ft_putnbr(main_struct->counter);
		ft_putchar('\n');
	}
}

void ft_change_fd(t_stacks *main_struct, t_flags *flags_struct)
{
	if ((main_struct->fd = open(flags_struct->file_name, O_RDONLY)) == -1)
	{
		ft_putstr_fd("Open/create file error\n", 2);
		ft_list_clear(&main_struct->a);
		ft_list_clear(&main_struct->b);
		exit (1);
	}
}

int		main(int argc, char **argv)
{
    t_stacks    main_struct;
	t_flags		flags_struct;
	char		*command;

	ft_initialization(&flags_struct, &main_struct, 0);
    if (argc < 2)
		ft_show_usage_ch();
    if (!(ft_parse_and_fill(&main_struct, &flags_struct, argc, argv)))
		ft_error();
	ft_check_duplicates(&main_struct);
	if (flags_struct.file_mode)
		ft_change_fd(&main_struct, &flags_struct);
	while (get_next_line(main_struct.fd, &command) > 0)
	{
		ft_apply_commands(&main_struct, command);
		if (flags_struct.debug_mode == 1)
			ft_debag(main_struct.a, main_struct.b, command);
		free(command);
	}
	ft_check_sort(&main_struct, flags_struct);
	if (flags_struct.file_mode)
		close(main_struct.fd);
	ft_list_clear(&main_struct.a);
    ft_list_clear(&main_struct.b);
    return (0);
}
#include "../push_swap_files/push_swap.h"

void	ft_apply_commands(t_stacks *main_struct, char *command)
{
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

void ft_check_sort(t_stacks    *main_struct)
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
}

int		main(int argc, char **argv)
{
    t_stacks    main_struct;
	char *command;

	main_struct.debug_mode = 0;
	command = 0;
    if (argc < 2 || (argc == 2 && argv[1][0] == '-'))
    	return (0);
    if (!(ft_parse_and_fill(&main_struct, argc, argv)))
		ft_error();
	ft_check_duplicates(&main_struct);
	while (get_next_line(0, &command) > 0)
	{
		ft_apply_commands(&main_struct, command);
		if (main_struct.debug_mode == 1)
			ft_print_stacks(main_struct.a, main_struct.b, command);
		free(command);
	}
	ft_check_sort(&main_struct);
	ft_list_clear(&main_struct.a);
    ft_list_clear(&main_struct.b);
    return (0);
}
#include "push_swap.h"

int		ft_check_command(char *command, t_stacks *main_struct)
{
    if ((ft_strcmp("sa", command) != 0) && (ft_strcmp("sb", command) != 0)
        && (ft_strcmp("ss", command) != 0) && (ft_strcmp("pb", command) != 0)
        && (ft_strcmp("pa", command) != 0) && (ft_strcmp("ra", command) != 0)
        && (ft_strcmp("rb", command) != 0) && (ft_strcmp("rr", command) != 0)
        && (ft_strcmp("rra", command) != 0) && (ft_strcmp("rrb", command) != 0)
        && (ft_strcmp("rrr", command) != 0))
    {
		ft_putstr_fd("Error\n", 2);
		ft_list_clear(&main_struct->a);
		ft_list_clear(&main_struct->b);
        exit (1);
    }
    return (1);
}

void	ft_apply_commands(t_stacks *main_struct, char *command)
{
	if (ft_strcmp("sa", command) == 0)
		SA;
	else if (ft_strcmp("sb", command) == 0)
		SB;
	else if (ft_strcmp("ss", command) == 0)
		SS;
	else if (ft_strcmp("pb", command) == 0)
		PB;
	else if (ft_strcmp("pa", command) == 0)
		PA;
	else if (ft_strcmp("ra", command) == 0)
		RA;
	else if (ft_strcmp("rb", command) == 0)
		RB;
	else if (ft_strcmp("rr", command) == 0)
		RR;
	else if (ft_strcmp("rra", command) == 0)
		RRA;
	else if (ft_strcmp("rrb", command) == 0)
		RRB;
	else if (ft_strcmp("rrr", command) == 0)
		RRR;
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
            ft_putstr("KO\n");
            exit (1);
        }
        main_struct->a = main_struct->a->next;
    }
    main_struct->a = begin;
    ft_putstr("OK\n");
}


int		main(int argc, char **argv)
{
    t_stacks    main_struct;
	char *command;

	command = 0;
    if (argc < 2)
        return (0);
    if (!(ft_parse_and_fill(&main_struct, argc, argv)))
	{
    	ft_putstr_fd("Error\n", 2);
    	return (1);
	}
	ft_check_duplicates(&main_struct);
	while (get_next_line(0, &command) > 0)
	{
		ft_check_command(command, &main_struct);
		ft_apply_commands(&main_struct, command);
		ft_strdel(&command);
	}
	ft_check_sort(&main_struct);
	ft_list_clear(&main_struct.a);
    ft_list_clear(&main_struct.b);
    return 0;
}

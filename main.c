#include "push_swap.h"

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

int		ft_check_command(char *command)
{
	if ((ft_strcmp("sa", command) != 0) && (ft_strcmp("sb", command) != 0)
	&& (ft_strcmp("ss", command) != 0) && (ft_strcmp("pb", command) != 0)
	&& (ft_strcmp("pa", command) != 0) && (ft_strcmp("ra", command) != 0)
	&& (ft_strcmp("rb", command) != 0) && (ft_strcmp("rr", command) != 0)
	&& (ft_strcmp("rra", command) != 0) && (ft_strcmp("rrb", command) != 0)
	&& (ft_strcmp("rrr", command) != 0))
	{
		printf("not valid command");
		exit (1);
	}
	return (1);
}

void ft_sort_check(t_stacks    *main_struct)
{
	t_lis *begin;

	if (!main_struct->a)
		return ;
	begin = main_struct->a;
	while (main_struct->a && main_struct->a->next)
	{
		if (main_struct->a->num > main_struct->a->next->num)
		{
			main_struct->a = begin;
			printf("KO\n");
			exit (1);
		}
		main_struct->a = main_struct->a->next;
	}
	main_struct->a = begin;
	printf("OK\n");
}

int		main(int argc, char **argv)
{
    t_stacks    main_struct;
	int ret;
	char *command;
	int fd;

	command = NULL;
	ret = 0;
    if (argc < 2)
        return (0);
    if (!(ft_parse_and_fill(&main_struct, argc, argv)))
	{
    	ft_putstr_fd("Error\n", 2);
		//printf("Error\n");
    	return (1);
	}
	printf("a - ");
	ft_print_list(main_struct.a);
	printf("\n");

	printf("b - ");
	ft_print_list(main_struct.b);
	printf("\n");
	while ((ret = get_next_line(0, &command)) > 0)
	{
		if (!ft_check_command(command))
			return (1);
		ft_apply_commands(&main_struct, command);
		ft_strdel(&command);
	}
	ft_sort_check(&main_struct);
	printf("a - ");
	ft_print_list(main_struct.a);
	printf("\n");

	printf("b - ");
	ft_print_list(main_struct.b);
	printf("\n");

/*printf("Make - SA");
	sa(&main_struct);
	printf("\n");
	printf("\n");

	printf("a - ");
	ft_print_list(main_struct.a);
	printf("\n");

	printf("b - ");
	ft_print_list(main_struct.b);
	printf("\n");

	printf("Make - 3 PB");
	pb(&main_struct);
	pb(&main_struct);
	pb(&main_struct);
	printf("\n");

	printf("a - ");
	ft_print_list(main_struct.a);
	printf("\n");

	printf("b - ");
	ft_print_list(main_struct.b);
	printf("\n");
	printf("\n");


	printf("Make - PA");
	pa(&main_struct);
	printf("\n");

	printf("a - ");
	ft_print_list(main_struct.a);
	printf("\n");

	printf("b - ");
	ft_print_list(main_struct.b);
	printf("\n");

	printf("Make - 2 SS");
	ss(&main_struct);
	printf("\n");
	printf("\n");

	printf("a - ");
	ft_print_list(main_struct.a);
	printf("\n");

	printf("b - ");
	ft_print_list(main_struct.b);
	printf("\n");
*/
/*	ra(&main_struct);
	printf("a - ");
	ft_print_list(main_struct.a);
	printf("\n");
	ra(&main_struct);
	printf("a - ");
	ft_print_list(main_struct.a);
	printf("\n");
	ra(&main_struct);
	printf("a - ");
	ft_print_list(main_struct.a);
	printf("\n");
	ra(&main_struct);
	printf("a - ");
	ft_print_list(main_struct.a);
	printf("\n");
	ra(&main_struct);
	printf("a - ");
	ft_print_list(main_struct.a);
	printf("\n");
	ra(&main_struct);
	printf("a - ");
	ft_print_list(main_struct.a);
	printf("\n");*/
/*printf("\n");
	PB;
	PB;
	PB;
	PB;
	PB;
	PB;
	PB;
	PB;
	PB;
	PB;
	PB;

	printf("after lots of PB\na - ");
	ft_print_list(main_struct.a);
	printf("\n");
	printf("b - ");
	ft_print_list(main_struct.b);
	printf("\n");
	printf("\n");

	PA;
	PA;
	PA;
	PA;


	printf("a - ");
	ft_print_list(main_struct.a);
	printf("\n");
	printf("b - ");
	ft_print_list(main_struct.b);
	printf("\n");
	printf("\n");*/
/*	rb(&main_struct);
	printf("b - ");
	ft_print_list(main_struct.b);
	printf("\n");
	rb(&main_struct);
	printf("b - ");
	ft_print_list(main_struct.b);
	printf("\n");
	rb(&main_struct);
	printf("b - ");
	ft_print_list(main_struct.b);
	printf("\n");
	rb(&main_struct);
	printf("b - ");
	ft_print_list(main_struct.b);
	printf("\n");
	rb(&main_struct);
	printf("b - ");
	ft_print_list(main_struct.b);
	printf("\n");
	rb(&main_struct);
	printf("b - ");
	ft_print_list(main_struct.b);
	printf("\n");*/
/*RRR;
	printf("a - rra - ");
	ft_print_list(main_struct.a);
	printf("\n");
	printf("b - rrb - ");
	ft_print_list(main_struct.b);
	printf("\n");
	printf("\n");
	printf("\n");
	RRR;
	printf("a - rra - ");
	ft_print_list(main_struct.a);
	printf("\n");
	printf("b - rrb - ");
	ft_print_list(main_struct.b);
	printf("\n");
	RRR;
	printf("a - rra - ");
	ft_print_list(main_struct.a);
	printf("\n");
	printf("b - rrb - ");
	ft_print_list(main_struct.b);
	printf("\n");
	RRR;
	SA;
	printf("a - rra - sa - ");
	ft_print_list(main_struct.a);
	printf("\n");
	printf("b - rrb - ");
	ft_print_list(main_struct.b);
	printf("\n");*/
/*rra(&main_struct);
	rrb(&main_struct);
	printf("a - ");
	ft_print_list(main_struct.a);
	printf("\n");
	printf("b - ");
	ft_print_list(main_struct.b);
	printf("\n");
	rra(&main_struct);
	rrb(&main_struct);
	printf("a - ");
	ft_print_list(main_struct.a);
	printf("\n");
	printf("b - ");
	ft_print_list(main_struct.b);
	printf("\n");
	rra(&main_struct);
	rrb(&main_struct);
	printf("a - ");
	ft_print_list(main_struct.a);
	printf("\n");
	printf("b - ");
	ft_print_list(main_struct.b);
	printf("\n");
	rra(&main_struct);
	rrb(&main_struct);
	printf("a - ");
	ft_print_list(main_struct.a);
	printf("\n");
	printf("b - ");
	ft_print_list(main_struct.b);
	printf("\n");
	rra(&main_struct);
	rrb(&main_struct);
	printf("a - ");
	ft_print_list(main_struct.a);
	printf("\n");
	printf("b - ");
	ft_print_list(main_struct.b);
	printf("\n");
	rra(&main_struct);
	rrb(&main_struct);
	printf("a - ");
	ft_print_list(main_struct.a);
	printf("\n");
	printf("b - ");
	ft_print_list(main_struct.b);
	printf("\n");*/
/*rr(&main_struct);
	printf("a - ");
	ft_print_list(main_struct.a);
	printf("\n");
	printf("b - ");
	ft_print_list(main_struct.b);
	printf("\n");

	rr(&main_struct);
	printf("a - ");
	ft_print_list(main_struct.a);
	printf("\n");
	printf("b - ");
	ft_print_list(main_struct.b);
	printf("\n");
	rr(&main_struct);
	printf("a - ");
	/ft_print_list(main_struct.a);
	printf("\n");
	printf("b - ");
	ft_print_list(main_struct.b);
	printf("\n");
	rr(&main_struct);
	printf("a - ");
	ft_print_list(main_struct.a);
	printf("\n");
	printf("b - ");
	ft_print_list(main_struct.b);
	printf("\n");*/

	ft_list_clear(&main_struct.a);
    ft_list_clear(&main_struct.b);



    return 0;
}

#include "push_swap.h"

int       main(int argc, char **argv)
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
		printf("Error\n");
    	return (0);
	}

	/*printf("a - ");
	ft_print_list(main_struct.a);
	printf("\n");

	printf("b - ");
	ft_print_list(main_struct.b);
	printf("\n");*/
/*	fd = open("/Users/ubartemi/Desktop/ubartemi4/2600-0.txt", O_RDONLY);
	if (fd == -1)
	{
		printf("fd = - 1");
		return (0);
	}
	while ((ret = get_next_line(fd, &command)) > 0)
	{
		printf("%s\n", command);
		ft_strdel(&command);
	}*/

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

#include "push_swap.h"

int       main(int argc, char **argv)
{
    t_stacks    main_struct;


    if (argc < 2)
        return (0);
    if (!(ft_parse_and_fill(&main_struct, argc, argv)))
	{
		printf("Error\n");
    	return (0);
	}
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

	ra(&main_struct);
	printf("a - ");
	ft_print_list(main_struct.a);
	printf("\n");
	ft_list_clear(&main_struct.a);
    ft_list_clear(&main_struct.b);
    return 0;
}

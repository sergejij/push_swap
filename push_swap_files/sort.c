#include "../push_swap.h"

void ft_sort_stack2(t_stacks *main_struct)
{
	if (main_struct->a->num > main_struct->a->next->num)
	{
		SA;
		ft_putstr("sa\n");
	}

}

void ft_sort_stack3(t_stacks *main_struct)
{
	int   first;
	int   second;
	int   third;

	first = main_struct->a->num;
	second = main_struct->a->next->num;
	third = main_struct->a->next->next->num;
	if (first > second && second < third && first < third)
	{
		SA;
		ft_putstr("sa\n");
	}
	else if (third < second && second < first)
	{
		SA;
		ft_putstr("sa\n");
		RRA;
		ft_putstr("rra\n");
	}
	else if (first > second && second < third && third < first)
	{
		RA;
		ft_putstr("ra\n");
	}
	else if (first < second && first < third && second > third)
	{
		SA;
		ft_putstr("sa\n");
		RA;
		ft_putstr("ra\n");
	}
	else if (first < second && first > third && second > third)
	{
		RRA;
		ft_putstr("rra\n");
	}
}

int ft_check_sort_ps(t_stacks    main_struct)
{
	t_lis *begin;

	if (!main_struct.a)
		return (0);
	begin = main_struct.a;
	while (main_struct.a && main_struct.a->next)
	{
		if (main_struct.a->num > main_struct.a->next->num)
			return (0);
		main_struct.a = main_struct.a->next;
	}
	main_struct.a = begin;
	return (1);
}

int is_ready_sort(t_stacks *main_struct)
{
	if (ft_check_sort_ps(*main_struct) && !(main_struct->b))
		return (1);
	return (0);
}
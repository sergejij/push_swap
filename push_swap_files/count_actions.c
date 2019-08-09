#include "push_swap.h"

int is_has_gap(t_stacks main_struct)
{
	t_lis *begin;

	begin = main_struct.a;
	while (main_struct.a && main_struct.a->next)
	{
		if (main_struct.a->num > main_struct.a->next->num)
			return (1);
		main_struct.a = main_struct.a->next;
	}
	main_struct.a = begin;
	return (0);
}

int ft_count_no_gap(t_stacks *main_struct, int item, int len_a)
{
	int num_item;
	t_lis *begin;

	begin = main_struct->a;
	num_item = 1;
	while (main_struct->a)
	{
		if (item > main_struct->a->num)
			num_item++;
		else
			break;
		main_struct->a = main_struct->a->next;
	}
	main_struct->b->common_and_pos_a_b[1] = num_item;
	main_struct->a = begin;
	return (ft_count_moves(num_item, len_a));
}

int ft_count_actions_in_a(t_stacks *main_struct, int item, int len_a)
{
	if (!is_has_gap(*main_struct))
		return (ft_count_no_gap(main_struct, item, len_a));
	else
		return (ft_count_has_gap(main_struct, item, len_a));
}

int ft_count_actions_in_b(t_lis *b, int item, int len_b)
{
	int num_item;
	t_lis *begin;

	begin = b;
	num_item = 1;
	while (b)
	{
		if (b->num == item)
			break;
		num_item++;
		b = b->next;
	}
	b->common_and_pos_a_b[2] = num_item;
	b = begin;
	return (ft_count_moves(num_item, len_b));
}

int ft_check_quantity_throw(t_stacks main_struct)
{
	int current_item;
	t_lis *begin;
	int tmp_count_actions;
	int result;

	result = main_struct.a_len + main_struct.b_len;
	begin = main_struct.b;
	while (main_struct.b)
	{
		current_item = main_struct.b->num; // будем менять
		tmp_count_actions = ft_count_actions_in_b(begin, current_item, main_struct.b_len)
							+ ft_count_actions_in_a(&main_struct, current_item, main_struct.a_len);
		main_struct.b->common_and_pos_a_b[0] = tmp_count_actions;
		if (tmp_count_actions < result)
			result = tmp_count_actions;
		main_struct.b = main_struct.b->next;
	}
	main_struct.b = begin;
	return (result);
}

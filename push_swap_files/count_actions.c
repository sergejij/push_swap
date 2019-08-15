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
	int lea;

	lea = len_a;
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
	return (num_item);
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
	int ba;

	ba = len_b;
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
	return (num_item);
}

int ft_count_double_and_single(t_stacks main_struct, t_lis *b, int current_item)
{
	int num_item_b;
	int num_item_a;
	int middle_b;
	int middle_a;
	int tmp;

	tmp = 0;
	middle_b = main_struct.b_len % 2 == 0 ? main_struct.b_len / 2 : (main_struct.b_len / 2) + 1;
	middle_a = main_struct.a_len % 2 == 0 ? main_struct.a_len / 2 : (main_struct.a_len / 2) + 1;
	num_item_b = ft_count_actions_in_b(b, current_item, main_struct.b_len);
	num_item_a = ft_count_actions_in_a(&main_struct, current_item, main_struct.a_len);
	if (num_item_b <= middle_b && num_item_a <= middle_a)
		while (num_item_b - 1 > 0 && num_item_a - 1 > 0)
		{
			tmp++;
			num_item_b--;
			num_item_a--;
		}
	else
		while (num_item_b < main_struct.b_len && num_item_a <= main_struct.a_len)
		{
			tmp++;
			num_item_b++;
			num_item_a++;
		}
	return (tmp + ft_count_moves(num_item_b, main_struct.b_len) + ft_count_moves(num_item_a, main_struct.a_len));
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
		current_item = main_struct.b->num;
		tmp_count_actions = ft_count_double_and_single(main_struct, begin, current_item);
		main_struct.b->common_and_pos_a_b[0] = tmp_count_actions;
		if (tmp_count_actions < result)
			result = tmp_count_actions;
		main_struct.b = main_struct.b->next;
	}
	main_struct.b = begin;
	return (result);
}
#include "push_swap.h"

void ft_final_rotates(t_stacks *main_struct, int num_item, int a_len)
{
	int middle;

	middle = a_len % 2 == 0 ? a_len / 2 : (a_len / 2) + 1;
	if (num_item <= middle)
		while (num_item-- - 1)
		{
			RA;
			ft_putstr("ra\n");
		}
	else if (main_struct->flag_stay_in_first != 1)
		while (num_item <= a_len && a_len > 1)
		{
			RRA;
			ft_putstr("rra\n");
			num_item++;
		}
	if (main_struct->debug_mode == 1)
		ft_print_stacks(main_struct);
}

void ft_eliminate_gap(t_stacks *main_struct, int a_len)
{
	int pos_after_gap;
	t_lis *begin;

	begin = main_struct->a;
	pos_after_gap = 1;
	if (!is_has_gap(*main_struct))
		return;
	while (main_struct->a && main_struct->a->next)
	{
		if (main_struct->a->num > main_struct->a->next->num)
		{
			pos_after_gap++;
			break;
		}
		pos_after_gap++;
		main_struct->a = main_struct->a->next;
	}
	main_struct->a = begin;
	ft_final_rotates(main_struct, pos_after_gap, a_len);
}

void ft_throw_without_seq(t_stacks *main_struct)
{
	while (((main_struct->a_len - 3) > 0))
	{
		PB;
		ft_putstr("pb\n");
		main_struct->a_len -= 1;
		main_struct->b_len += 1;
	}
}

void ft_throw_seq(t_stacks *main_struct, int start_seq, int len_seq)
{
	t_lis *begin;
	int i;
	int len_a;

	len_a = main_struct->a_len;
	begin = main_struct->a;
	i = 0;
	while (i <= len_a)
	{
		if (i == start_seq)
			while (i++ - start_seq < len_seq)
			{
				RA;
				ft_putstr("ra\n");
			}
		PB;
		ft_putstr("pb\n");
		main_struct->a_len -= 1;
		main_struct->b_len += 1;
		i++;
	}
}

void ft_find_sort_sequence(t_lis *stack_a, int *start_seq, int *len_seq)
{
	int counter;
	int tmp_end;
	t_lis *begin;

	begin = stack_a;
	counter = 0;
	tmp_end = 0;
	while (stack_a)
	{
		while (stack_a->next && stack_a->num < stack_a->next->num)
		{
			counter++;
			stack_a = stack_a->next;
			if (stack_a->next == NULL || stack_a->num > stack_a->next->num)
			{
				tmp_end = counter >= *len_seq ? stack_a->number_el : tmp_end;
				*len_seq = counter >= *len_seq ? counter : *len_seq;
				counter = 0;
			}
		}
		stack_a = stack_a->next;
	}
	if (tmp_end)
		*start_seq = tmp_end - *len_seq;
	stack_a = begin;
}

void ft_push_swap(t_stacks *main_struct)
{
	int start_seq;
	int len_seq;

	len_seq = 0;
	start_seq = 0;
	if (main_struct->debug_mode == 1)
		ft_print_stacks(main_struct);
	ft_find_sort_sequence(main_struct->a, &start_seq, &len_seq);
	if (len_seq > 3 && !is_ready_sort(main_struct))
		ft_throw_seq(main_struct, start_seq, len_seq);
	else if (!is_ready_sort(main_struct))
		ft_throw_without_seq(main_struct);
    while (!is_ready_sort(main_struct))
	{
        if (main_struct->a_len == 2)
            ft_sort_stack2(main_struct);
        else if (main_struct->a_len == 3)
            ft_sort_stack3(main_struct);
        if (main_struct->b_len > 0)
        {
			ft_throwing(main_struct);
			main_struct->a_len += 1;
			main_struct->b_len -= 1;
		}
        if (main_struct->b_len == 0)
			ft_eliminate_gap(main_struct, main_struct->a_len);
    }
}

int main(int argc, char **argv)
{
    t_stacks    main_struct;
    main_struct.debug_mode = 0;
    if (argc < 2)
        return (0);
    if (!(ft_parse_and_fill(&main_struct, argc, argv)))
		ft_error();
    ft_check_duplicates(&main_struct);
    ft_push_swap(&main_struct);
	ft_list_clear(&main_struct.a);
	ft_list_clear(&main_struct.b);
    return (0);
}
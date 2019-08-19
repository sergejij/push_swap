#include "push_swap.h"

void ft_throw_without_seq(t_stacks *main_struct)
{
	while (((main_struct->a_len - 3) > 0))
	{
		ft_print_command(main_struct, "pb");
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
			while (i - start_seq < len_seq)
			{
				ft_print_command(main_struct, "ra");
				i++;
			}
		ft_print_command(main_struct, "pb");
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
				tmp_end = counter > *len_seq ? stack_a->number_el : tmp_end;
				*len_seq = counter > *len_seq ? counter : *len_seq;
				counter = 0;
			}
		}
		stack_a = stack_a->next;
	}
	if (tmp_end)
		*start_seq = tmp_end - *len_seq;
	stack_a = begin;
}
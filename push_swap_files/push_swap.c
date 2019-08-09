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

void ft_push_swap(t_stacks *main_struct)
{
	main_struct->is_first = 1;
    while (!is_ready_sort(main_struct)) // циклит пока не отсортирует
	{
    	if (main_struct->is_first)
			while (((main_struct->a_len - 3) > 0))
			{
				main_struct->is_first = 0;
				PB;
				ft_putstr("pb\n");
				main_struct->a_len -= 1;
				main_struct->b_len += 1;
			}
        if (main_struct->a_len == 2)
            ft_sort_stack2(main_struct);
        else if (main_struct->a_len == 3)
            ft_sort_stack3(main_struct);
        if (main_struct->b_len > 0)
        {
			ft_throwing(main_struct); // перебрасывание из б в а
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
    if (argc < 2)
        return (0);
    if (!(ft_parse_and_fill(&main_struct, argc, argv)))
    {
        ft_putstr_fd("Error\n", 2);
        return (1);
    }
    ft_check_duplicates(&main_struct);
    ft_push_swap(&main_struct);
	ft_list_clear(&main_struct.a);
	ft_list_clear(&main_struct.b);
    return (0);
}
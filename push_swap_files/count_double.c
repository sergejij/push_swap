#include "push_swap.h"

int ft_count_single(t_stacks *main_struct, int num_item, int len_stack)
{
	int middle;
	int counter;

	counter = 0;
	middle = len_stack % 2 == 0 ? len_stack / 2 : (len_stack / 2) + 1;
	if (num_item <= middle)
		while (num_item-- - 1 > 0)
			counter++;
	else if (main_struct->flag_stay_in_first != 1)
		while (num_item <= len_stack && len_stack > 1)
		{
			counter++;
			num_item++;
		}
	return (counter);
}

int ft_count_double(t_stacks *main_struct, int num_item_a, int num_item_b)
{
	int middle_b;
	int middle_a;
	int counter;

	counter = 0;
	middle_b = main_struct->b_len / 2;
	middle_a = main_struct->a_len / 2;
	if (num_item_b <= middle_b && num_item_a <= middle_a)
		while ((num_item_b - 1) > 0 && num_item_a - 1 > 0)
		{
			counter++;
			ft_change_meanings(&num_item_a, &num_item_b, '-');
		}
	else
		while ((num_item_a < main_struct->a_len  && num_item_a > middle_a)
			   && (num_item_b <= main_struct->b_len && num_item_b > middle_b))
		{
			counter++;
			ft_change_meanings(&num_item_a, &num_item_b, '+');
		}
	return (counter + ft_count_single(main_struct, num_item_b, main_struct->b_len)
			+ ft_count_single(main_struct, num_item_a, main_struct->a_len));
}

int	is_need_double(t_stacks *main_struct, int num_item_a, int num_item_b)
{
	int number_of_double;
	int number_of_single;

	number_of_double = ft_count_double(main_struct, num_item_a, num_item_b);
	number_of_single = ft_count_single(main_struct, num_item_b, main_struct->b_len)
					   + ft_count_single(main_struct, num_item_a, main_struct->a_len);
	if (number_of_double >= number_of_single)
		return (0);
	return (1);
}
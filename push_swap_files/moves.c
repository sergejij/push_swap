#include "push_swap.h"

int	ft_count_moves(int num_item, int len_stack)
{
	int middle;
	int counter;

	counter = 0;
	middle = (len_stack / 2) % 2 == 0 ? len_stack / 2 : (len_stack / 2) + 1;
	if (len_stack == 1 || len_stack < num_item)
		return (0);
	if (num_item <= middle)
		while (num_item-- - 1)
			counter++;
	else
		while (num_item++ <= len_stack)
			counter++;
	return (counter);
}

void ft_rotate_double(t_stacks *main_struct, int *num_item_a, int *num_item_b)
{
	int middle_b;
	int middle_a;
	int *len_b;
	int *len_a;

	len_b = &main_struct->b_len;
	len_a = &main_struct->a_len;
	middle_b = (*len_b) % 2 == 0 ? (*len_b) / 2 : ((*len_b) / 2) + 1;
	middle_a = (*len_a) % 2 == 0 ? (*len_a) / 2 : ((*len_a) / 2) + 1;
	if ((*num_item_b) <= middle_b && (*num_item_a) <= middle_a)
		while (((*num_item_b) - 1) > 0 && ((*num_item_a) - 1) > 0)
		{
			RR;
			ft_putstr("rr\n");
			(*num_item_b)--;
			(*num_item_a)--;
		}
	else if ((*num_item_b) >= middle_b && (*num_item_a) >= middle_a)
		while (((*num_item_a) < (*len_a)  && (*num_item_a) > middle_a)
		&& ((*num_item_b) <= (*len_b) && (*num_item_b) > middle_b))
		{
			RRR;
			ft_putstr("rrr\n");
			(*num_item_a)++;
			(*num_item_b)++;
		}

}

void ft_rotate(t_stacks *main_struct, int num_item, int len_stack, char which_stack)
{
	int middle;

	middle = len_stack % 2 == 0 ? len_stack / 2 : (len_stack / 2) + 1;
	if (num_item <= middle)
		while (num_item-- - 1 > 0)
		{
			which_stack == 'a' ? RA : RB;
			which_stack == 'a' ? ft_putstr("ra\n") : ft_putstr("rb\n");
		}
	else if (main_struct->flag_stay_in_first != 1)
		while (num_item <= len_stack && len_stack > 1)
		{
			which_stack == 'a' ? RRA : RRB;
			which_stack == 'a' ? ft_putstr("rra\n") : ft_putstr("rrb\n");
			num_item++;
		}
	if (main_struct->b && which_stack == 'a')
	{
		PA;
		ft_putstr("pa\n");
	}
}



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
	int len_b;
	int len_a;
	int counter;

	counter = 0;
	len_b = main_struct->b_len;
	len_a = main_struct->a_len;
	middle_b = len_b % 2 == 0 ? len_b / 2 : (len_b) / 2 + 1;
	middle_a = len_a % 2 == 0 ? len_a / 2 : (len_a) / 2 + 1;
	if (num_item_b <= middle_b && num_item_a <= middle_a)
		while ((num_item_b - 1) > 0 && num_item_a - 1 > 0)
		{
			counter++;
			num_item_b--;
			num_item_a--;
		}
	else
		while ((num_item_a < len_a  && num_item_a > middle_a)
			   && (num_item_b <= len_b && num_item_b > middle_b))
		{
			counter++;
			num_item_a++;
			num_item_b++;
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

void ft_move_common(t_stacks *main_struct, int num_item_a, int num_item_b)
{/*
	if (main_struct->debug_mode == 1)
		ft_print_stacks(main_struct);*/
	if (is_need_double(main_struct, num_item_a, num_item_b))
		ft_rotate_double(main_struct, &num_item_a, &num_item_b);
	ft_rotate(main_struct, num_item_b, main_struct->b_len, 'b');
	ft_rotate(main_struct, num_item_a, main_struct->a_len, 'a');
	/*if (main_struct->debug_mode == 1)
		ft_print_stacks(main_struct);*/
}


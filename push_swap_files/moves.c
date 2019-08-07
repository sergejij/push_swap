#include "../push_swap.h"

int	ft_count_moves(int num_item, int len_stack)
{
	int middle;
	int counter;
	int m;

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

void ft_move_no_gap(t_stacks *main_struct, int len_a, int item)
{
	int middle;

	middle = len_a / 2;
	if (main_struct->b->common_and_pos_a_b[1] <= middle)
		while (main_struct->b->common_and_pos_a_b[1]-- + 1)
		{
			RA;
			ft_putstr("ra\n");
			PA;
			ft_putstr("pa\n");
		}
	else
	{
		while (main_struct->b->common_and_pos_a_b[1]++ < len_a)
		{
			RRA;
			ft_putstr("rra\n");
			PA;
			ft_putstr("pa\n");
		}
	}
}

void ft_move_common(t_stacks *main_struct, int num_item, int len_stack, char which_stack)
{
	int middle;

	middle = len_stack % 2 == 0 ? len_stack / 2 : (len_stack / 2) + 1;
	if (num_item <= middle)
		while (num_item-- - 1)
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

void ft_move_b(t_stacks *main_struct, int item_b, int len_b)
{
	int middle;

	middle = len_b / 2;
	if (item_b <= middle)
		while (item_b-- - 1)
		{
			RB;
			ft_putstr("rb\n");
		}
	else
		while (item_b++ - 2 < len_b)
		{
			RRB;
			ft_putstr("rrb\n");
		}
}
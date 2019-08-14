#include "push_swap.h"

void ft_find_pos_after_gap(t_stacks *main_struct, int item,  int *num_item, int *is_not_found)
{
	int i;
	t_lis *begin;

	begin = main_struct->a;
	i = 1;
	while (i++ < (*num_item))
		main_struct->a = main_struct->a->next;
	if (!main_struct->a)
		(*num_item) -= 1;
	while ((*is_not_found) && main_struct->a && main_struct->a->next)
	{
		if (main_struct->a->num < main_struct->a->next->num)
		{
			if (item > main_struct->a->num)
				(*num_item)++;
			else
				break;
			main_struct->a = main_struct->a->next;
		}
		else
			break;
	}
	if (begin->num > item && (*num_item) == main_struct->a_len && main_struct->a->num < item)
	{
		(*num_item) = 1;
		return;
	}
}

int	ft_count_has_gap(t_stacks *main_struct, int item, int len_a)
{
	int num_item;
	t_lis *begin;
	int is_not_found;
	int a;

	a = len_a;
	is_not_found = 1;
	begin = main_struct->a;
	num_item = 1;
	ft_find_gap(main_struct, item,  &num_item, &is_not_found);
	if (is_not_found && main_struct->a && !main_struct->a->next && item < main_struct->a->num)
		return (1);
	if (is_not_found)
		ft_find_pos_after_gap(main_struct, item,  &num_item, &is_not_found);
	main_struct->b->common_and_pos_a_b[1] = num_item;
	main_struct->a = begin;
	return (num_item);
}

void ft_find_gap(t_stacks *main_struct, int item,  int *num_item, int *is_not_found)
{
	t_lis *begin;

	begin = main_struct->a;
	while (main_struct->a && main_struct->a->next)
	{
		if (main_struct->a->num < main_struct->a->next->num)
		{
			if (main_struct->a->num < item && (main_struct->a->next->num > item))
			{
				(*is_not_found) = 0;
				(*num_item)++;
				break;
			}
			(*num_item)++;
			main_struct->a = main_struct->a->next;
			continue;
		}
		else
		{
			if (main_struct->a->num < item)
				(*is_not_found) = 0;
			(*num_item)++;
			break;
		}
	}
	main_struct->a = begin;
}


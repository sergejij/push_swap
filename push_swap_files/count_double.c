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
	else if (main_struct->is_first != 1)
		while (num_item <= len_stack && len_stack > 1)
		{
			counter++;
			num_item++;
		}
	return (counter);
}

int ft_count_double(t_stacks *m_struct, int num_i_a, int num_i_b)
{
	int middle_b;
	int middle_a;
	int counter;

	counter = 0;
	middle_b = m_struct->b_len / 2;
	middle_a = m_struct->a_len / 2;
	if (num_i_b <= middle_b && num_i_a <= middle_a)
		while ((num_i_b - 1) > 0 && num_i_a - 1 > 0)
			ft_change_meanings(&num_i_a, &num_i_b, &counter, '-');
	else
		while ((num_i_a < m_struct->a_len  && num_i_a > middle_a)
			   && (num_i_b <= m_struct->b_len && num_i_b > middle_b))
			ft_change_meanings(&num_i_a, &num_i_b, &counter, '+');
	return (counter + ft_count_single(m_struct, num_i_b, m_struct->b_len)
			+ ft_count_single(m_struct, num_i_a, m_struct->a_len));
}

int	is_need_double(t_stacks *m_struct, int num_i_a, int num_i_b)
{
	int number_of_double;
	int number_of_single;

	number_of_double = ft_count_double(m_struct, num_i_a, num_i_b);
	number_of_single = ft_count_single(m_struct, num_i_b, m_struct->b_len)
					   + ft_count_single(m_struct, num_i_a, m_struct->a_len);
	if (number_of_double >= number_of_single)
		return (0);
	return (1);
}
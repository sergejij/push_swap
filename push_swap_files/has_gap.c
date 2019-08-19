#include "push_swap.h"

void ft_pos_after_gap(t_stacks *m_struct, int el,  int *n_item, int *is_not_f)
{
	int i;
	t_lis *b;

	b = m_struct->a;
	i = 1;
	while (i++ < (*n_item))
		m_struct->a = m_struct->a->next;
	if (!m_struct->a)
		(*n_item) -= 1;
	while ((*is_not_f) && m_struct->a && m_struct->a->next)
	{
		if (m_struct->a->num < m_struct->a->next->num)
		{
			if (el > m_struct->a->num)
				(*n_item)++;
			else
				break;
			m_struct->a = m_struct->a->next;
		}
		else
			break;
	}
	if (b->num > el && (*n_item) == m_struct->a_len && m_struct->a->num < el)
		(*n_item) = 1;
}

int	ft_count_has_gap(t_stacks *m_struct, int item)
{
	int num_item;
	t_lis *begin;
	int is_not_f;

	is_not_f = 1;
	begin = m_struct->a;
	num_item = 1;
	ft_find_gap(m_struct, item,  &num_item, &is_not_f);
	if (is_not_f && m_struct->a && !m_struct->a->next
		&& item < m_struct->a->num)
		return (1);
	if (is_not_f)
		ft_pos_after_gap(m_struct, item,  &num_item, &is_not_f);
	m_struct->b->common_and_pos_a_b[1] = num_item;
	m_struct->a = begin;
	return (num_item);
}

void ft_find_gap(t_stacks *m_struct, int item,  int *n_item, int *is_not_f)
{
	t_lis *begin;

	begin = m_struct->a;
	while (m_struct->a && m_struct->a->next)
	{
		if (m_struct->a->num < m_struct->a->next->num)
		{
			if (m_struct->a->num < item && (m_struct->a->next->num > item))
			{
				(*is_not_f) = 0;
				(*n_item)++;
				break;
			}
			(*n_item)++;
			m_struct->a = m_struct->a->next;
			continue;
		}
		else
		{
			if (m_struct->a->num < item)
				(*is_not_f) = 0;
			(*n_item)++;
			break;
		}
	}
	m_struct->a = begin;
}


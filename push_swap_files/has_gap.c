/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   has_gap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubartemi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 14:40:27 by ubartemi          #+#    #+#             */
/*   Updated: 2019/08/19 14:51:06 by ubartemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		is_has_gap(t_stacks main_struct)
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

void	ft_pos_after_gap(t_stacks *m_struc, int el, int *n_item, int *is_not_f)
{
	int		i;
	t_lis	*b;

	b = m_struc->a;
	i = 1;
	while (i++ < (*n_item))
		m_struc->a = m_struc->a->next;
	if (!m_struc->a)
		(*n_item) -= 1;
	while ((*is_not_f) && m_struc->a && m_struc->a->next)
	{
		if (m_struc->a->num < m_struc->a->next->num)
		{
			if (el > m_struc->a->num)
				(*n_item)++;
			else
				break ;
			m_struc->a = m_struc->a->next;
		}
		else
			break ;
	}
	if (b->num > el && (*n_item) == m_struc->a_len && m_struc->a->num < el)
		(*n_item) = 1;
}

int		ft_count_has_gap(t_stacks *m_struct, int item)
{
	int		num_item;
	t_lis	*begin;
	int		is_not_f;

	is_not_f = 1;
	begin = m_struct->a;
	num_item = 1;
	ft_find_gap(m_struct, item, &num_item, &is_not_f);
	if (is_not_f && m_struct->a && !m_struct->a->next
		&& item < m_struct->a->num)
		return (1);
	if (is_not_f)
		ft_pos_after_gap(m_struct, item, &num_item, &is_not_f);
	m_struct->b->common_and_pos_a_b[1] = num_item;
	m_struct->a = begin;
	return (num_item);
}

int		ft_find_gap2(t_stacks *m_struct, int item, int *n_item, int *is_not_f)
{
	if (m_struct->a->num < item && (m_struct->a->next->num > item))
	{
		(*is_not_f) = 0;
		(*n_item)++;
		return (1);
	}
	(*n_item)++;
	m_struct->a = m_struct->a->next;
	return (0);
}

void	ft_find_gap(t_stacks *m_struct, int item, int *n_item, int *is_not_f)
{
	t_lis *begin;

	begin = m_struct->a;
	while (m_struct->a && m_struct->a->next)
	{
		if (m_struct->a->num < m_struct->a->next->num)
		{
			if (ft_find_gap2(m_struct, item, n_item, is_not_f))
				break ;
			continue;
		}
		else
		{
			if (m_struct->a->num < item)
				(*is_not_f) = 0;
			(*n_item)++;
			break ;
		}
	}
	m_struct->a = begin;
}

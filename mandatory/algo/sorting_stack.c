/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: messkely <messkely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 22:37:01 by messkely          #+#    #+#             */
/*   Updated: 2024/03/18 16:00:59 by messkely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	indexing_stack(t_list **lst)
{
	int		index;
	t_list	*tmp;
	t_list	*max_n;
	int		max_v;

	tmp = NULL;
	index = ft_lstsize(*lst) - 1;
	while (index)
	{
		tmp = *lst;
		max_v = INT_MIN;
		while (tmp)
		{
			if (tmp->data > max_v && tmp->index == 0)
			{
				max_v = tmp->data;
				max_n = tmp;
			}
			tmp = tmp->next;
		}
		max_n->index = index;
		index--;
	}
}

void	short_sort(t_list **a)
{
	int	higher;

	higher = get_major_index(*a);
	if ((*a)->index == higher)
		ra(a);
	else if ((*a)->next->index == higher)
		rra(a);
	if ((*a)->data > (*a)->next->data)
		sa(a);
}

void	ft_sort_stack(t_list **a, t_list **b)
{
	if (ft_lstsize(*a) == 2)
		sa(a);
	else if (ft_lstsize(*a) == 3)
		short_sort(a);
	else
	{
		if (ft_lstsize(*a) <= 100)
			push_a_to_b(a, b, 10);
		else if (ft_lstsize(*a) >= 100)
			push_a_to_b(a, b, 30);
		return_to_a(a, b);
	}
}

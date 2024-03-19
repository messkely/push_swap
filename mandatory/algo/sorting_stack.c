/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: messkely <messkely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 22:37:01 by messkely          #+#    #+#             */
/*   Updated: 2024/03/19 08:40:10 by messkely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	indexing_stack(t_list **lst)
{
	int		index;
	t_list	*tmp;
	t_list	*major_node;
	int		major_value;

	tmp = NULL;
	index = ft_lstsize(*lst) - 1;
	while (index)
	{
		tmp = *lst;
		major_value = INT_MIN;
		while (tmp)
		{
			if (tmp->data > major_value && tmp->index == 0)
			{
				major_value = tmp->data;
				major_node = tmp;
			}
			tmp = tmp->next;
		}
		major_node->index = index;
		index--;
	}
}

void	sort_3(t_list **a)
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

void	sort_4(t_list **a, t_list **b)
{
	int	min_index;

	min_index = 0;
	while (ft_lstsize(*a) > 3)
	{
		if ((*a)->index == min_index)
			pb(a, b);
		else if ((*a)->next->index == min_index)
		{
			sa(a);
			pb(a, b);
		}
		else
			rra(a);
	}
	sort_3(a);
	pa(a, b);
}

void	sort_5(t_list **a, t_list **b)
{
	int	min_index;

	min_index = 0;
	while (ft_lstsize(*a) > 3)
	{
		if ((*a)->index == min_index)
		{
			pb(a, b);
			min_index++;
		}
		else if ((*a)->next->index == min_index)
		{
			sa(a);
			pb(a, b);
			min_index++;
		}
		else
			rra(a);
	}
	sort_3(a);
	pa(a, b);
	pa(a, b);
}

void	ft_sort_stack(t_list **a, t_list **b)
{
	if (ft_lstsize(*a) == 2)
		sa(a);
	else if (ft_lstsize(*a) == 3)
		sort_3(a);
	else if (ft_lstsize(*a) == 4)
		sort_4(a, b);
	else if (ft_lstsize(*a) == 5)
		sort_5(a, b);
	else
	{
		if (ft_lstsize(*a) <= 100)
			push_a_to_b(a, b, 10);
		else if (ft_lstsize(*a) >= 100)
			push_a_to_b(a, b, 30);
		return_to_a(a, b);
	}
}

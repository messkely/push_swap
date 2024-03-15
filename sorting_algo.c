/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_algo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: messkely <messkely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 22:37:01 by messkely          #+#    #+#             */
/*   Updated: 2024/03/15 12:56:32 by messkely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

int	get_major_index(t_list *lst)
{
	t_list	*tmp;
	int		higher;

	tmp = lst;
	higher = tmp->index;
	while (tmp)
	{
		if (tmp->index > higher)
			higher = tmp->index;
		tmp = tmp->next;
	}
	return (higher);
}

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

void	long_sort(t_list **a, t_list **b)
{
	void
}

void	push_a_to_b(t_list **a, t_list **b, int delimeter)
{
	int	i;

	i = 0;
	while (ft_lstsize(*a) > 0)
	{
		if ((*a)->index <= i)
		{
			pb(a, b);
			i++;
		}
		else if ((*a)->index <= (i + delimeter))
		{
			pb(a, b);
			rb(b);
			i++;
		}
		else
			ra(a);
	}
}

int	ft_check(t_list *b, int index)
{
	int		size;
	int		i;
	t_list	*tmp;

	size = ft_lstsize(b);
	i = 0;
	tmp = b;
	while (i < size / 2 && tmp)
	{
		if (index == tmp->index)
			return (1);
		tmp = tmp->next;
		i++;
	}
	return (0);
}

void	turn_to_a(t_list **a, t_list **b)
{
	int	max_index;

	max_index = get_higher_index(*b);
	while (ft_lstsize(*b) > 0)
	{
		if (*b && (*b)->index == max_index)
		{
			pa(a, b);
			max_index--;
		}
		else if ((*b)->next->index == max_index)
		{
			sb(b);
			pa(a, b);
			max_index--;
		}
		else
		{
			if (!ft_check(*b, max_index))
				rrb(b);
			else
				rb(b);
		}
	}
}

void	ft_sort_stack(t_list **a, t_list **b)
{
	(void)b;
	if (ft_lstsize(*a) == 2)
		sa(a);
	else if (ft_lstsize(*a) == 3)
		sort_3(a);
	else
		long_sort(a, b);
}
  
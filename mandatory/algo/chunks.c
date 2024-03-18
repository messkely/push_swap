/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: messkely <messkely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 22:47:16 by messkely          #+#    #+#             */
/*   Updated: 2024/03/18 15:45:52 by messkely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

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

int	ft_check_stack(t_list *b, int index)
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

void	return_to_a(t_list **a, t_list **b)
{
	int	max_index;

	max_index = get_major_index(*b);
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
			if (!ft_check_stack(*b, max_index))
				rrb(b);
			else
				rb(b);
		}
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: messkely <messkely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 09:06:23 by messkely          #+#    #+#             */
/*   Updated: 2024/03/19 11:05:09 by messkely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/checker.h"

void	swap(t_list **lst)
{
	t_list	*tmp;

	if (*lst && (*lst)->next)
	{
		tmp = (*lst)->next;
		(*lst)->next = tmp->next;
		ft_add_front(lst, tmp);
	}
}

void	sa(t_list **a)
{
	swap(a);
}

void	sb(t_list **b)
{
	swap(b);
}

void	ss(t_list **a, t_list **b)
{
	swap(a);
	swap(b);
}

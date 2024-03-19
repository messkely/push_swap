/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: messkely <messkely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 22:42:26 by messkely          #+#    #+#             */
/*   Updated: 2024/03/19 11:04:35 by messkely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/checker.h"

void	push(t_list **dest, t_list **src)
{
	t_list	*tmp;

	tmp = *src;
	if (*src == NULL)
		return ;
	*src = (*src)->next;
	tmp->next = NULL;
	ft_add_front(dest, tmp);
}

void	pa(t_list **a, t_list **b)
{
	push(a, b);
}

void	pb(t_list **a, t_list **b)
{
	push(b, a);
}

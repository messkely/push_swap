/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: messkely <messkely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 22:42:26 by messkely          #+#    #+#             */
/*   Updated: 2024/03/11 00:10:39 by messkely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	push(t_list **dest, t_list **src)
{
	t_list	*top_node;

	if (!(*src))
		return ;
	top_node = *src;
	*src = (*src)->next;
	if (*src)
		(*src)->prev = 0;
	if (*dest)
	{
		top_node->next = *dest;
		*dest = top_node;
		(*dest)->next->prev = *dest;
	}
	else
	{
		top_node->next = 0;
		*dest = top_node;
	}
}

void	pa(t_list **a, t_list **b)
{
	push(a, b);
	write(1, "pa\n", 3);
}

void	pb(t_list **b, t_list **a)
{
	push(b, a);
	write(1, "pb\n", 3);
}
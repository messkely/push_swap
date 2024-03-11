/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: messkely <messkely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 22:45:45 by messkely          #+#    #+#             */
/*   Updated: 2024/03/11 00:07:38 by messkely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	rotate(t_list **head)
{
	t_list	*last_node;

	if (!(*head) || !(*head)->next)
		return ;
	last_node = ft_lastNode(*head);
	last_node->next = *head;
	*head = (*head)->next;
	last_node->next->prev = last_node;
	(*head)->prev = 0;
	last_node->next->next = 0;
}

void	ra(t_list **a)
{
	rotate(a);
		write(1, "ra\n", 3);
}

void	rb(t_list **b)
{
	rotate(b);
		write(1, "rb\n", 3);
}

void	rr(t_list **a, t_list **b)
{
	rotate(a);
	rotate(b);
		write(1, "rr\n", 3);
}
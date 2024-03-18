/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: messkely <messkely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 22:46:51 by messkely          #+#    #+#             */
/*   Updated: 2024/03/17 15:10:43 by messkely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	rev_rotate(t_list **lst)
{
	t_list	*head;
	t_list	*last;

	if (!(*lst) || !(*lst)->next)
		return ;
	head = *lst;
	last = ft_last_node(*lst);
	while (head->next->next != NULL)
		head = head->next;
	head->next = NULL;
	last->next = (*lst);
	(*lst) = last;
}

void	rra(t_list **a)
{
	rev_rotate(a);
	write(1, "rra\n", 4);
}

void	rrb(t_list **b)
{
	rev_rotate(b);
	write(1, "rrb\n", 4);
}

void	rrr(t_list **a, t_list **b)
{
	rev_rotate(a);
	rev_rotate(b);
	write(1, "rrr\n", 4);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: messkely <messkely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 22:42:26 by messkely          #+#    #+#             */
/*   Updated: 2024/03/20 22:52:53 by messkely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

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
	write(1, "pa\n", 3);
	push(a, b);
}

void	pb(t_list **a, t_list **b)
{
	write(1, "pb\n", 3);
	push(b, a);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list_utils_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: messkely <messkely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 13:51:11 by messkely          #+#    #+#             */
/*   Updated: 2024/03/19 09:39:21 by messkely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/checker.h"

t_list	*ft_add_new_node(int data)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->data = data;
	new->index = 0;
	new->next = NULL;
	return (new);
}

t_list	*ft_last_node(t_list *head)
{
	if (!head)
		return (NULL);
	while (head->next)
		head = head->next;
	return (head);
}

void	ft_add_back(t_list **head, t_list *new)
{
	t_list	*last;

	if (*head == NULL)
	{
		*head = new;
		return ;
	}
	last = ft_last_node(*head);
	last->next = new;
}

void	ft_add_front(t_list **head, t_list *new)
{
	if (*head)
		new->next = *head;
	*head = new;
}

int	ft_lstsize(t_list *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

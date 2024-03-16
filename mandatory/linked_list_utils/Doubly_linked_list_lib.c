/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Doubly_linked_list_lib.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: messkely <messkely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 13:51:11 by messkely          #+#    #+#             */
/*   Updated: 2024/03/16 14:06:04 by messkely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

t_list	*ft_add_new_node(int data)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->data = data;
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

void	printList(t_list *head)
{
	while (head)
	{
		printf("%d ",head->data);
		head = head->next;
	}
	printf("\n");
}

int main()
{
	t_list *head = ft_add_new_node(18);
	ft_add_back(&head, ft_add_new_node(19));
	ft_add_back(&head, ft_add_new_node(20));
	ft_add_front(&head, ft_add_new_node(17));

	printList(head);
	printf("%d\n",ft_lstsize(head));
}
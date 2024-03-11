/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: messkely <messkely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 22:47:16 by messkely          #+#    #+#             */
/*   Updated: 2024/03/08 04:41:01 by messkely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void printCircularList(t_list *head) {
    t_list *current = head;
    if (head != NULL) {
        while (1) {
            printf("%d ", current->data);
            current = current->next;
            if (current == head)
                break;
        }
    }
    printf("\n");
}

void addNodeToEnd(t_list **head, int data) {
    t_list *newNode = ft_lstnew(data);
    if (newNode == NULL)
        return;
    if (*head == NULL) {
        *head = newNode;
        newNode->next = newNode;
    } else {
        t_list *last = *head;
        while (last->next != *head) {
            last = last->next;
        }
        last->next = newNode;
        newNode->next = *head;
    }
}

void ft_swap(t_list **lst)
{
	t_list *tmp;

	if (!(*lst) || !(*lst)->next)
		return ;
	ft_lstadd_front(lst, (*lst)->next);
}

void ft_print(int data)
{
	printf("%d ", data);
}


int main()
{
	t_list *head = ft_lstnew(10);
	t_list *data1 = ft_lstnew(20);
	t_list *data2 = ft_lstnew(30);
	t_list *data3 = ft_lstnew(40);

	head->next = data1;
	data1->next = data2;
	data2->next = data3;
	data3->next = NULL;
	printCircularList(head);
	// addNodeToEnd(&head, data2);
	ft_swap(&head);
	ft_lstadd_back(&head,data2);
	printCircularList(head);
}
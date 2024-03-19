/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printList.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: messkely <messkely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 14:31:59 by messkely          #+#    #+#             */
/*   Updated: 2024/03/19 09:06:06 by messkely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	print_list(t_list *head)
{
	while (head)
	{
		printf("%d ", head->data);
		head = head->next;
	}
	printf("\n");
}

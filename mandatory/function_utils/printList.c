/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printList.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: messkely <messkely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 14:31:59 by messkely          #+#    #+#             */
/*   Updated: 2024/03/20 12:34:01 by messkely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	print_list(t_list *head)
{
	while (head)
	{
		printf("%d ", head->index);
		head = head->next;
	}
	printf("\n");
}

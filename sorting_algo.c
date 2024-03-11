/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_algo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: messkely <messkely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 22:37:01 by messkely          #+#    #+#             */
/*   Updated: 2024/03/11 00:31:28 by messkely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

void	ft_sort_stack(t_list **stack_a, t_list **stack_b)
{
	(void)stack_b;
	if (ft_lstsize(*stack_a) == 2)
		sa(stack_a);
	else if (ft_lstsize(*stack_a) == 3)
		if ((*stack_a)->data > (*stack_a)->next->data)
		sa(stack_a);
}
132
213
231
312
321

321 -> 32 1 -> 23 1 -> 123
213 -> 123
231 -> 31 2 -> 13 2 -> 213 -> 123
  
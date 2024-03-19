/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_stack_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: messkely <messkely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 11:51:11 by messkely          #+#    #+#             */
/*   Updated: 2024/03/19 09:39:01 by messkely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/checker.h"

void	ft_fill_stack(char **arr, t_list **lst)
{
	int	i;

	i = 0;
	while (arr[i])
		ft_add_back(lst, ft_add_new_node(ft_atoi(arr[i++])));
	ft_broom(arr);
}

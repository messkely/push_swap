/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: messkely <messkely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 08:47:30 by messkely          #+#    #+#             */
/*   Updated: 2024/03/10 23:58:25 by messkely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

int	main(int ac, char *av[])
{
	char	**arr;
	t_list	*a;
	t_list	*b;

	a = NULL;
	b = NULL;
	if (ac > 1)
	{
		arr = ft_check_error(ac, av);
		ft_isduplicat(arr);
		ft_fill_stack(arr, &a);
		if (is_sorted(a))
			ft_error();
		ft_sort_stack(&a, &b);
		printList(a);
		free_stack(a);
	}
	return (0);
}

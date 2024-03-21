/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: messkely <messkely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 08:47:30 by messkely          #+#    #+#             */
/*   Updated: 2024/03/21 15:35:29 by messkely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int ac, char **av)
{
	char	**arr;
	t_list	*a;
	t_list	*b;

	a = NULL;
	b = NULL;
	if (ac > 1)
	{
		arr = ft_parssing(ac, av);
		ft_isduplicat(arr);
		ft_fill_stack(arr, &a);
		if (is_sorted(a))
			exit(0);
		indexing_stack(&a);
		ft_sort_stack(&a, &b);
		print_list(a);
		free_stack(a);
	}
	return (0);
}

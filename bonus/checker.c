/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: messkely <messkely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 09:23:54 by messkely          #+#    #+#             */
/*   Updated: 2024/03/22 00:36:14 by messkely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

void	check_instructions(t_list **a, t_list **b)
{
	if (is_sorted(*a) && ft_lstsize(*b) == 0)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free_stack(*a);
	free_stack(*b);
}

void	ft_check_is_sorted(t_list *a)
{
	if (is_sorted(a))
		exit(0);
}

int	main(int ac, char **av)
{
	t_list	*a;
	t_list	*b;
	char	*str;
	char	**arr;

	if (ac == 1)
		return (0);
	if (read(0, NULL, 0) < 0)
		ft_error();
	arr = NULL;
	arr = ft_parssing(ac, av);
	ft_fill_stack(arr, &a);
	ft_check_is_sorted(a);
	while (ac > 1)
	{
		str = get_next_line(0);
		if (!str)
		{
			free(str);
			break ;
		}
		ft_check_moves(str, &a, &b);
		free(str);
	}
	check_instructions(&a, &b);
}

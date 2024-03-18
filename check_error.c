/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: messkely <messkely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 23:02:50 by messkely          #+#    #+#             */
/*   Updated: 2024/03/17 15:06:29 by messkely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	is_empty(const char *str)
{
    if (!str)
        return 1;
    while (*str != '\0')
    {
        if (!ft_isspace((unsigned char)*str))
            return 0;
        str++;
    }
    return 1;
}


int	is_syntax_err(char *str)
{
	int	i;

	i = 0;
	while (i == 0 || str[i])
	{
		if (i == 0 && (str[i] != '+' && str[i] != '-'
				&& (str[i] < '0' || str[i] > '9')))
			return (1);
		if (i == 0 && (str[i] == '+' || str[i] == '-') && !str[i + 1])
			return (1);
		if (i > 0 && (str[i] < '0' || str[i] > '9'))
			return (1);
		i++;
	}
	return (0);
}

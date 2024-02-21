/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: messkely <messkely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 09:06:23 by messkely          #+#    #+#             */
/*   Updated: 2024/02/21 09:21:59 by messkely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

ft_is_sorted(char **str)
{
    int i = 1;
    int j;
    while (str[i])
    {
        j = 0;
        while (str[i][j])
        {
            if (!ft_isdigit(str[i][j]))
                return (0);
            j++;
        }
        i++;
    }
    
}
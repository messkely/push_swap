/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parssing_utils_2_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: messkely <messkely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 12:03:25 by messkely          #+#    #+#             */
/*   Updated: 2024/03/22 00:24:53 by messkely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/checker.h"

long	ft_atoi(const char *str)
{
	int		i;
	int		sign;
	long	res;

	i = 0;
	res = 0;
	sign = 1;
	while (ft_isspace(str[i]) && str[i])
		i++;
	if ((str[i] == '-' || str[i] == '+') && str[i])
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (ft_isdigit(str[i]) && str[i])
	{
		res = res * 10 + (str[i++] - 48);
		if ((res * sign) < -2147483648 && (res * sign) > 2147483647)
			return (2147483649);
	}
	return (sign * res);
}

void	ft_isduplicat(char **str)
{
	int	i;
	int	j;

	i = 0;
	if (ft_atoi(str[0]) < -2147483648 || ft_atoi(str[0]) > 2147483647)
		return (ft_error());
	while (str[i])
	{
		j = i + 1;
		while (str[j])
		{
			if ((ft_atoi(str[i]) == ft_atoi(str[j]))
				|| (ft_atoi(str[j]) < -2147483648
					|| ft_atoi(str[j]) > 2147483647))
				return (ft_error());
			j++;
		}
		i++;
	}
}

char	*ft_strjoinn(char *s1, char *s2)
{
	char	*ptr;
	size_t	i;
	size_t	j;

	if (!s1)
	{
		s1 = (char *)malloc(1 * sizeof(char));
		s1[0] = '\0';
	}
	ptr = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!ptr)
		return (0);
	i = 0;
	while (s1[i])
	{
		ptr[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
		ptr[i++] = s2[j++];
	ptr[i] = '\0';
	free(s1);
	return (ptr);
}

void	ft_check_error(char *av)
{
	int		j;

	j = 0;
	while (av[j])
	{
		if (ft_isdigit(av[j]) && (av[j + 1] == '-' || av[j + 1] == '+'))
			ft_error();
		if (av[j] == '+' || av[j] == '-')
			j++;
		if (!ft_isdigit(av[j]) && av[j] != ' ')
			ft_error();
		j++;
	}
}

char	**ft_parssing(int ac, char **av)
{
	char	*buff;
	char	**res;
	int		i;

	buff = NULL;
	i = 1;
	while (i < ac)
	{
		if (!ft_isempty(av[i]))
		{
			ft_check_error(av[i]);
			buff = ft_strjoinn(buff, av[i++]);
			buff = ft_strjoinn(buff, " ");
		}
		else
			ft_error();
	}
	res = ft_split(buff, ' ');
	ft_isduplicat(res);
	return (free(buff), res);
}

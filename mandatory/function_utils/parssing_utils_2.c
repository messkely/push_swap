/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parssing_utils_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: messkely <messkely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 12:03:25 by messkely          #+#    #+#             */
/*   Updated: 2024/03/19 09:02:07 by messkely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

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
		if (res * sign > INT_MAX || res * sign < INT_MIN)
			return (2147483648);
	}
	return (sign * res);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ptr;
	size_t	i;
	size_t	j;

	if (!s1 || !s2)
		return (NULL);
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
	return (ptr);
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

char	*ft_check_error(int ac, char **av, char *buff)
{
	int		i;
	int		j;

	i = 1;
	while (i < ac)
	{
		if (!ft_isempty(av[i]))
		{
			j = 0;
			while (av[i][j])
			{
				if (av[i][j] == '+' || av[i][j] == '-')
					j++;
				if (!ft_isdigit(av[i][j]) && av[i][j] != ' ')
					ft_error();
				j++;
			}
			buff = ft_strjoin(buff, av[i++]);
			buff = ft_strjoin(buff, " ");
		}
		else
			ft_error();
	}
	return (buff);
}

char	**ft_parssing(int ac, char **av)
{
	char	*buff;
	char	**res;

	buff = "";
	buff = ft_check_error(ac, av, buff);
	res = ft_split(buff, ' ');
	return (free(buff), res);
}

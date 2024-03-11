/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parssing_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: messkely <messkely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 01:49:28 by messkely          #+#    #+#             */
/*   Updated: 2024/03/10 22:26:50 by messkely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_isdigit(int c)
{
	return (c >= 48 && c <= 57);
}

int	ft_isspace(char c)
{
	return ((c >= 9 && c <= 13) || c == ' ');
}

int	ft_isempty(const char *str)
{
	if (!str)
		return (1);
	while (*str != '\0')
	{
		if (!ft_isspace((unsigned char)*str))
			return (0);
		str++;
	}
	return (1);
}

void	ft_error(void)
{
	write(1, "Error", 5);
	exit(1);
}

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

void	ft_broom(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		free(arr[i++]);
	free(arr);
}

char	**ft_check_error(int ac, char **av)
{
	int		i;
	int		j;
	char	*r1;
	char	**r2;

	i = 1;
	r1 = "";
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
			r1 = ft_strjoin(r1, av[i++]);
			r1 = ft_strjoin(r1, " ");
		}
		else
			ft_error();
	}
	r2 = ft_split(r1, ' ');
	free(r1);
	return (r2);
}

void	ft_fill_stack(char **arr, t_list **lst)
{
	int	i;

	i = 0;
	while (arr[i])
		ft_addBack(lst, ft_addNewNode(ft_atoi(arr[i++])));
	ft_broom(arr);
}

void	free_stack(t_list *stack)
{
	t_list	*tmp;

	while (stack)
	{
		tmp = stack->next;
		free(stack);
		stack = tmp;
	}
	stack = NULL;
}

int	is_sorted(t_list *lst)
{
	if (!lst)
		return (0);
	while (lst->next)
	{
		if (lst->data > lst->next->data)
			return (0);
		lst = lst->next;
	}
	return (1);
}

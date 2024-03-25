/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: messkely <messkely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 09:10:10 by messkely          #+#    #+#             */
/*   Updated: 2024/03/22 00:36:24 by messkely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "../lib/get_next_line/get_next_line.h"
# include <limits.h>

typedef struct d_list
{
	int				data;
	int				index;
	struct d_list	*next;
}					t_list;

t_list	*ft_add_new_node(int data);
t_list	*ft_last_node(t_list *head);
void	ft_add_back(t_list **head, t_list *new);
void	ft_add_front(t_list **head, t_list *new);
int		ft_lstsize(t_list *lst);

size_t	ft_strlen(const char *s);
int		ft_isdigit(int c);
int		ft_isspace(char c);
int		ft_isempty(const char *str);
long	ft_atoi(const char *str);
char	**ft_split(const char *s, char c);
void	ft_error(void);
void	ft_isduplicat(char **str);
char	*ft_strjoinn(char *s1, char *s2);
void	ft_check_error(char *av);
char	**ft_parssing(int ac, char **av);
int		ft_strcmp(char *s1, char *s2);
void	ft_check_is_sorted(t_list *a);
void	ft_check_moves(char *str, t_list **a, t_list **b);
void	check_instructions(t_list **a, t_list **b);

void	ft_fill_stack(char **av, t_list **lst);
int		is_sorted(t_list *lst);

void	swap(t_list **lst);
void	sa(t_list **a);
void	sb(t_list **b);
void	ss(t_list **a, t_list **b);
void	push(t_list **dest, t_list **src);
void	pa(t_list **a, t_list **b);
void	pb(t_list **b, t_list **a);
void	rotate(t_list **lst);
void	ra(t_list **a);
void	rb(t_list **b);
void	rr(t_list **a, t_list **b);
void	rev_rotate(t_list **lst);
void	rra(t_list **a);
void	rrb(t_list **b);
void	rrr(t_list **a, t_list **b);

void	ft_broom(char **arr);
void	free_stack(t_list *stack);

#endif
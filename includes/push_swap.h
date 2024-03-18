/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: messkely <messkely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 10:26:24 by messkely          #+#    #+#             */
/*   Updated: 2024/03/17 16:40:21 by messkely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
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
void	print_list(t_list *head);

size_t	ft_strlen(const char *s);
int		ft_isdigit(int c);
int		ft_isspace(char c);
int		ft_isempty(const char *str);
long	ft_atoi(const char *str);
char	*ft_strjoin(char const *s1, char const *s2);
char	**ft_split(const char *s, char c);
void	ft_error(void);
void	ft_isduplicat(char **str);
char	*ft_check_error(int ac, char **av);
char	**ft_parssing(int ac, char **av);

void	ft_fill_stack(char **av, t_list **lst);
int		is_sorted(t_list *lst);
void	ft_sort_stack(t_list **a, t_list **b);
void	short_sort(t_list **a);
int		get_major_index(t_list *lst);
void	indexing_stack(t_list **lst);
void	push_a_to_b(t_list **a, t_list **b, int delimeter);
int		ft_check_stack(t_list *b, int index);
void	return_to_a(t_list **a, t_list **b);

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
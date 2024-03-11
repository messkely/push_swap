#include "includes/push_swap.h"

t_list	*ft_addNewNode(int data)
{
	t_list *new;

	new = (t_list *)malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->prev = NULL;
	new->data = data;
	new->next = NULL;
	return (new);
}

t_list	*ft_lastNode(t_list *head)
{
	if (!head)
		return (NULL);
	while (head->next)
		head = head->next;
	return (head);
}

void	ft_addBack(t_list **head, t_list *new)
{
	t_list *last;

	if (*head == NULL)
	{
		*head = new;
		return ;
	}
	last = ft_lastNode(*head);
	last->next = new;
	new->prev = last;
}

void	ft_addFront(t_list **head, t_list *new)
{
	if (!*head)
		*head = new;
	else
	{
		new->next = *head;
		(*head)->prev = new;
		*head = new;
	}
}

int		ft_lstsize(t_list *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

void	printList(t_list *head)
{
	while (head)
	{
		printf("%d ",head->data);
		head = head->next;
	}
	printf("\n");
}

// int main()
// {
// 	t_list *head = ft_addNewNode(18);
// 	ft_addBack(&head, ft_addNewNode(19));
// 	ft_addBack(&head, ft_addNewNode(20));
// 	ft_addFront(&head, ft_addNewNode(17));

// 	printList(head);
// 	printf("%d\n",ft_lstsize(head));
// }
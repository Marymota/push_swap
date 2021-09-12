#include "push_swap.h"

void swap(t_list *stack)
{
	void *first_node;

	first_node = stack->data;
	stack->data = stack->next->data;
	stack->next->data = first_node;
	printf("sa\n");
}

void rotate(t_list **stack)
{
	t_list *node;

	node = *stack;
	if (!node || !node->next)
		return ;
	*stack = node->next;
	node->next = 0;
	ft_lstadd_back(stack, node);
	printf("ra\n");
}

void reverse_rotate(t_list **stack)
{
	t_list *tmp;
	t_list *node;

	tmp = *stack;
	if (!tmp || !tmp->next)
		return ;
	while (tmp->next->next)
		tmp = tmp->next;
	node = tmp->next;
	tmp->next = 0;
	ft_lstadd_front(stack, node);
	printf("rra\n");
}
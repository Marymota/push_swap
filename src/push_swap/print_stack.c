#include "push_swap.h"

void	print_stack(t_list *stack)
{
	t_list	*node;
	int		len;

	len = ft_lstsize(stack);
	node = stack;
	printf("\n----------");
	while (len--)
	{
		printf("\nstack: %li", (long int)node->data);
		node = node->next;
	}
	printf("\n----------\n\n");
}

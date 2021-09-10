#include "push_swap.h"

void sort(int args, t_list **stack_a, t_list **stack_b)
{
	(void)stack_b;
	if (args <= 4)
	{
		printf("sort small: \n");
		sort_small(*stack_a);
	}
}
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
	void *data;

	data = (*stack)->data;
	ft_lstadd_back(stack, ft_lstnew(data));
	//ft_lstrm_node(stack);
	*stack = (*stack)->next;
	printf("ra\n");
}

void reverse_rotate(t_list *stack)
{
	void *data;
	t_list *node;

	ft_lstiter(stack, 0);
	data = stack->data;
	node = ft_lstnew(data);
	ft_lstdelone(stack, 0);
	ft_lstadd_front(&stack, node);
}

void sort_small(t_list *stack)
{
	void	*min;
	int		*max;

	min = (void *)ft_lstget_min(stack);
	max = (void *)ft_lstget_max(stack);
	printf("min %i max: %i\n", (int)min, (int)max);
	while (!ft_lstsorted(stack))
	{
		if (stack->data == max && stack->next->data == min)
		{
			rotate(&stack);
		}
		else if (stack->data == min || (stack->data > stack->next->data))
		{
			swap(stack);
		}

		//else
		//{
		//	reverse_rotate(stack);
		//	printf("rra\n");
		//}

	}
}


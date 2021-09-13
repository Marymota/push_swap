#include "push_swap.h"

void sort_medium(t_list **stack_a, t_list **stack_b)
{
	void	*min;
	int		*max;
	int 	len;

	min = (void *)ft_lstget_min(*stack_a);
	max = (void *)ft_lstget_max(*stack_a);
	len = ft_lstsize(*stack_a);
	//printf("min %i max: %i len: %i\n", (int)min, (int)max, len);
	while (len-- > 3)
	{
		push(stack_a, stack_b);
		printf("pb\n");
	}
	sort_small(stack_a);
	push(stack_b, stack_a);
	printf("pa\n");
	sort_small(stack_a);
	push(stack_b, stack_a);
	sort_small(stack_a);
}

void sort_small(t_list **stack)
{
	void	*min;
	int		*max;

	min = (void *)ft_lstget_min(*stack);
	max = (void *)ft_lstget_max(*stack);
	printf("min %i max: %i\n", (int)min, (int)max);
	while (!ft_lstsorted(*stack))
	{
		if ((*stack)->data == max && (*stack)->next->data == min)
		{
			rotate(stack);
			printf("ra\n");
		}
		else if ((*stack)->data == min || (*stack)->data > (*stack)->next->data)
		{
			swap(*stack);
			printf("sa\n");
		}
		else
		{
			reverse_rotate(stack);
			printf("rra\n");
		}
	}
}

void sort(int args, t_list **stack_a, t_list **stack_b)
{
	if (args <= 4)
	{
		printf("sort small: \n");
		sort_small(stack_a);
	}
	else if (args <= 6)
	{
		printf("sort medium: \n");
		sort_medium(stack_a, stack_b);
	}
}



#include "push_swap.h"

void sort(int args, t_list **stack_a, t_list **stack_b)
{
	(void)stack_b;
	if (args <= 4)
	{
		printf("sort small: \n");
		sort_small(stack_a);
	}
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
		}
		else if ((*stack)->data == min || (*stack)->data > (*stack)->next->data)
		{
			swap(*stack);
		}
		else
		{
			reverse_rotate(stack);
		}

	}
}


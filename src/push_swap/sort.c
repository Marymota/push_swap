#include "push_swap.h"

void sort_medium(t_list **stack_a, t_list **stack_b, int min, int max)
{
	int len;
	len = ft_lstsize(*stack_a);
	//printf("min %i max: %i len: %i\n", (int)min, (int)max, len);
	while (len-- > 3)
	{
		push(stack_a, stack_b);
		printf("pb\n");
	}
	sort_small(stack_a, min, max);
	if (stack_b)
	{
		push(stack_b, stack_a);
		printf("pa\n");
	}
	while (!ft_lstsorted(*stack_a))
	{
		//printf("stack: %i, max: %i\n", (int)(*stack_a)->data, (int)max);
		if ((int)(*stack_a)->data == max || (int)(*stack_b)->data == max)
		{
			rotate(stack_a);
			printf("ra\n");
		}
		else
		{
			if ((int)(*stack_a)->data > (int)(*stack_a)->next->data)
			{
				swap(*stack_a);
				printf("sa\n");
				if (!ft_lstsorted(*stack_a))
				{
					push(stack_a, stack_b);
					printf("pb\n");
					sort_small(stack_a, min, max);
					if (stack_b)
					{
						push(stack_b, stack_a);
					printf("pa\n");
				}
					if (!ft_lstsorted(*stack_a))
					{
						push(stack_a, stack_b);
						printf("pb\n");
						sort_small(stack_a, min, max);
					}
				}
				else
				{
					push(stack_b, stack_a);
					printf("pa\n");
				}
			}
		}
		if (stack_b)
		{
			push(stack_b, stack_a);
			printf("pa\n");
		}
	}
}

void sort_small(t_list **stack, int min, int max)
{
	while (!ft_lstsorted(*stack))
	{
		if ((int)(*stack)->data == max && (int)(*stack)->next->data == min)
		{
			rotate(stack);
			printf("ra\n");
		}
		else if ((int)(*stack)->data == min || (*stack)->data > (*stack)->next->data)
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
	long int	min;
	long int	max;

	min = (long int)ft_lstget_min(*stack_a);
	max = (long int)ft_lstget_max(*stack_a);
	if (args <= 4)
	{
		printf("sort small: \n");
		sort_small(stack_a, min, max);
	}
	else if (args <= 6)
	{
		printf("sort medium: \n");
		sort_medium(stack_a, stack_b, min, max);
	}
}



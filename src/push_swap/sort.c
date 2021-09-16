#include "push_swap.h"




int ft_lstget_idx(t_list *lst, void *value)
{
	int i;

	i = 0;
	while (lst)
	{
		if (value == lst->data)
			return (i);
		lst = lst->next;
		++i;
	}
	return (-2147483648);
}

int range (t_list *stack_a, t_list *limits)
{
	t_list *dup_a;
	int imax;
	int imin;
	long int	min;
	long int	max;

	dup_a = ft_lstdup(stack_a);
	min = (long int)ft_lstget_min(stack_a);
	max = (long int)ft_lstget_max(stack_a);
	ft_lstsort(&dup_a);
	imax = ft_lstget_idx(dup_a, limits->data);
	imin = ft_lstget_idx(dup_a, limits->next->data);
	ft_lstclear(&dup_a, &free);
	return (imax - imin + 1);
}

void sort_large(t_list **stack_a, t_list **stack_b, long int min, long int max)
{	
	t_list *limits;

	(void)stack_a;
	(void)stack_b;
	limits = ft_lstnew((void *)min);
	ft_lstadd_back(&limits, ft_lstnew((void *)max));
	while (limits != NULL)
	{
		printf("limits: %li\n", (long int)limits->data);
		limits = limits->next;
	}
	if (ft_lstsize(limits) == 2)
	{
		if (range(*stack_a, limits) >= 20)
		{
			//get_limits(limits, *stack_a);
			;
		}
	}
}

void sort_medium(t_list **stack_a, t_list **stack_b, int min, int max)
{
	while (ft_lstsize(*stack_a) > 3)
	{
		while ((int)(*stack_a)->data != min)
		{
			if ((int)(*stack_a)->next->data != min && (int)(*stack_a)->data != min)
			{
				reverse_rotate(stack_a);
				printf("rra\n");
			}
			else
			{
				rotate(stack_a);
				printf("ra\n");	
			}
		}
		push(stack_a, stack_b);
		printf("pb\n");
		min = ft_lstget_min(*stack_a);
	}
	sort_small(stack_a, min, max);
	while (*stack_b)
	{
		push(stack_b, stack_a);
		printf("pa\n");
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
		//printf("sort small: \n");
		sort_small(stack_a, min, max);
	}
	else if (args <= 6)
	{
		//printf("sort medium: \n");
		sort_medium(stack_a, stack_b, min, max);
	}
	else
	{
		//sort_medium(stack_a, stack_b, min, max);
		sort_large(stack_a, stack_b, min, max);
	}
		
	//printf("\nMoves: %i\n\n", i);
}



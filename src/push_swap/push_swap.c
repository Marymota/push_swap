#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = 0;
	stack_b = 0;
	get_stack(&stack_a, argc, &argv[1]);
	if (!ft_lstsorted(stack_a))
		sort(argc - 1, &stack_a, &stack_b);
	ft_exit(0, &stack_a, &stack_b);
	return (0);
}

void	sort(int args, t_list **stack_a, t_list **stack_b)
{
	void		*min;
	void		*max;
	t_list		*limits;

	limits = 0;
	min = (void *)ft_lstget_min(*stack_a);
	max = (void *)ft_lstget_max(*stack_a);
	ft_lstadd_front(&limits, ft_lstnew(max));
	ft_lstadd_front(&limits, ft_lstnew(min));
	if (args <= 3)
		sort_small(stack_a, min, max);
	else if (args <= 5)
		sort_medium(stack_a, stack_b, min, max);
	else
		sort_large(stack_a, stack_b, &limits);
}

void	sort_small(t_list **stack, void *min, void *max)
{
	while (!ft_lstsorted(*stack))
	{
		if ((*stack)->data == max && (*stack)->next->data == min)
			rotate(stack, "ra\n" );
		else if ((*stack)->data == min || (*stack)->data > (*stack)->next->data)
			swap(*stack, "sa\n");
		else
			reverse_rotate(stack, "rra\n");
	}
}

void	sort_medium(t_list **stack_a, t_list **stack_b, void *min, void *max)
{
	if ((*stack_a)->next->data == min)
		rotate(stack_a, "ra\n");
	else if ((void *)ft_lstlast(*stack_a) == min)
		reverse_rotate(stack_a, "rra\n");
	while (ft_lstsize(*stack_a) > 3 && !ft_lstsorted(*stack_a))
	{
		while ((*stack_a)->data != min)
		{
			if ((*stack_a)->next->next->data == min || (*stack_a)->next->data == min)
				rotate(stack_a, "ra\n");
			else
				reverse_rotate(stack_a, "rra\n");
		}
		if (!ft_lstsorted(*stack_a))
		{
			push(stack_a, stack_b, "pb\n");
			min = (void *)ft_lstget_min(*stack_a);
		}
	}
	sort_small(stack_a, min, max);
	while (*stack_b)
		push(stack_b, stack_a, "pa\n");
}

void	sort_large(t_list **stack_a, t_list **stack_b, t_list **limits)
{	
	int	ra_cnt;
	int	lim_len;

	if (ft_lstsize(*limits) == 1)
		return ;
	lim_len = get_limits(*limits, *stack_a);
	ra_cnt = split_stack(stack_a, stack_b, *limits, lim_len);
	if (ft_lstsize(*stack_a) != ft_lstsize(*stack_b))
		if (ft_lstsize(*stack_a) + 1 != ft_lstsize(*stack_b))
			while (ra_cnt--)
				reverse_rotate(stack_a, "rra\n");
	if (ft_lstsize(*stack_b) <= 20)
	{
		merge_b_into_a_ordering(stack_a, stack_b);
		ft_lstdel_first(limits, ft_lstdel_int);
	}
	else
	{
		merge_btwn_limits(stack_a, stack_b, limits, ft_lstsize(*stack_b));
		ft_lstsort(limits);
		ft_lstdel_first(limits, ft_lstdel_int);
	}
	sort_large(stack_a, stack_b, limits);
	rotate_until_sorted(stack_a);
	ft_lstclear(limits, ft_lstdel_int);
}

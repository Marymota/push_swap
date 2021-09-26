#include "push_swap.h"

int	min_max_close_top(t_list *stack, int min, int max)
{
	int	len;
	int	i_min;
	int	i_max;

	len = ft_lstsize(stack);
	i_min = ft_lstget_idx(stack, min);
	i_max = ft_lstget_idx(stack, max);
	if ((i_min < i_max) && (i_min < (len - i_max)))
		return (1);
	else if (i_max < (len - i_min))
		return (1);
	return (0);
}

int	node_next_to_last(t_list *stack_a, t_list *stack_b)
{
	t_list		*dup;
	int			first;
	int			last;
	long int	data_last_node;

	data_last_node = (long int)ft_lstlast(stack_a)->data;
	dup = ft_lstdup(stack_a);
	ft_lstadd_back(&dup, ft_lstdup(stack_b));
	ft_lstsort(&dup);
	first = ft_lstget_idx(dup, (long int)stack_a->data);
	last = ft_lstget_idx(dup, data_last_node);
	ft_lstclear(&dup, ft_lstdel_int);
	if (last == (first - 1))
		return (1);
	else
		return (0);
}

void	rotate_until_sorted(t_list **stack)
{
	int	min;
	int	half_len;
	int	index;

	min = ft_lstget_min(*stack);
	half_len = ft_lstsize(*stack) / 2;
	index = ft_lstget_idx(*stack, (long int)min);
	if (index < half_len)
	{
		while ((long int)(*stack)->data != min)
			rotate(stack, "ra\n");
	}
	else
	{
		while ((long int)(*stack)->data != min)
			reverse_rotate(stack, "rra\n");
	}
}

void	merge_b_into_a_ordering (t_list **stack_a, t_list **stack_b)
{
	int	min;
	int	max;

	while (*stack_b)
	{
		min = ft_lstget_min(*stack_b);
		max = ft_lstget_max(*stack_b);
		if ((int)(*stack_a)->data < min && min_max_close_top(*stack_b, min, max))
			rotate_ab(stack_a, stack_b);
		else if ((int)(*stack_a)->data < min)
			rotate(stack_a, "ra\n");
		else if ((int)(*stack_b)->data == max)
			push(stack_b, stack_a, "pa\n");
		else if ((int)(*stack_b)->data == min)
			push(stack_b, stack_a, "pa\n");
		else if (min_max_close_top(*stack_b, min, max))
			rotate(stack_b, "rb\n");
		else
			reverse_rotate(stack_b, "rrb\n");
	}
}

int	split_stack(t_list **stack_a, t_list **stack_b, t_list *limits, int lim_len)
{
	int	ra_cnt;

	ra_cnt = 0;
	while (lim_len)
	{
		if ((long int)limits->data <= (long int)(*stack_a)->data
			&& (long int)(*stack_a)->data < (long int)limits->next->data)
		{
			lim_len--;
			if (node_next_to_last(*stack_a, *stack_b))
				rotate(stack_a, "ra\n");
			else
				push(stack_a, stack_b, "pb\n");
		}
		else
		{
			if ((long int)(*stack_a)->data >= (long int)limits->data)
				ra_cnt++;
			rotate(stack_a, "ra\n");
		}
	}
	return (ra_cnt);
}

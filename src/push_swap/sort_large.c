#include "push_swap.h"

int	is_min_max_closer_to_top(t_list *stack, int min, int max)
{
	int	len;
	int	i_min;
	int	i_max;
	int	check;

	len = ft_lstsize(stack);
	i_min = ft_lstget_idx(stack, min);
	i_max = ft_lstget_idx(stack, max);
	if (i_min < i_max)
		check = (i_min < (len - i_max));
	else
		check = (i_max < (len - i_min));
	return (check);
}

int	first_node_sorted(t_list *stack_a, t_list *stack_b)
{
	t_list		*dup;
	int			first;
	int			last;
	long int	data_last_node;

	//printf("\nstack_a: %li %li %li\n", (long int)stack_a->data, (long int)stack_a->next->data, (long int)stack_a->next->next->data);

	data_last_node = (long int)ft_lstlast(stack_a)->data;
	dup = ft_lstdup(stack_a);
	ft_lstadd_back(&dup, ft_lstdup(stack_b));
	ft_lstsort(&dup);
	first = ft_lstget_idx(dup, (long int)stack_a->data);
	last = ft_lstget_idx(dup, data_last_node);
	//printf("\nstack: %li, first: %i, last: %i\n", (long int)stack_a->data, first, last);
	ft_lstclear(&dup, ft_lstdel_int);
	if (last == (first - 1) && ft_lstsize(stack_a) > last)
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

void	merge_btwn_limits(t_list **stack_a, t_list **stack_b, t_list **limits, int len)
{
	int	curr_len;
	int	tmp;

	tmp = 0;
	if (len == 0 || !(*stack_b))
		return ;
	ft_lstadd_front(limits, ft_lstnew((void *)ft_lstget_median(*stack_b)));
	curr_len = len;
	while (curr_len > len / 2 && *stack_b)
	{
		if ((long int)(*limits)->data <= (long int)(*stack_b)->data && curr_len--)
			push(stack_b, stack_a, "pa\n");
		else if ((long int)(*stack_b)->data == ft_lstget_min(*stack_b))
		{
			tmp++;
			push(stack_b, stack_a, "pa\n");
			if (*stack_b != 0)
				rotate(stack_a, "ra\n");
		}
		else
			rotate(stack_b, "rb\n");
	}
	merge_btwn_limits(stack_a, stack_b, limits, curr_len - tmp);
}

void	merge_b_into_a_ordering (t_list **stack_a, t_list **stack_b)
{
	int	min;
	int	max;

	while (*stack_b)
	{
		min = ft_lstget_min(*stack_b);
		max = ft_lstget_max(*stack_b);
		if ((long int)(*stack_a)->data < min && is_min_max_closer_to_top(*stack_b, min, max))
			rotate_ab(stack_a, stack_b);
		else if ((long int)(*stack_a)->data < min)
			rotate(stack_a, "ra\n");
		else if ((long int)(*stack_b)->data == max)
			push(stack_b, stack_a, "pa\n");
		else if ((long int)(*stack_b)->data == min)
			push(stack_b, stack_a, "pa\n");
		else if (is_min_max_closer_to_top(*stack_b, min, max))
			rotate(stack_b, "rb\n");
		else
			reverse_rotate(stack_b, "rrb\n");
	}
}

int	split_stack(t_list **stack_a, t_list **stack_b, t_list *limits, int lim_len)
{
	//int	first_split;
	int	ra_cnt;

	//first_split = ft_lstsize(*stack_a) / 2 == lim_len;
	//printf("\nstack_a: %li %li %li\n", (long int)(*stack_a)->data, (long int)(*stack_a)->next->data, (long int)(*stack_a)->next->next->data);
	ra_cnt = 0;
	while (lim_len)
	{
		if ((long int)limits->data <= (long int)(*stack_a)->data
			&& (long int)(*stack_a)->data < (long int)limits->next->data)
		{
			lim_len--;
			if (first_node_sorted(*stack_a, *stack_b)) /*&& !first_split*/
				rotate(stack_a, "ra\n");
			else
				push(stack_a, stack_b, "pb\n");
		}
		else if ((long int)(*stack_a)->data < (long int)limits->data)
			rotate(stack_a, "ra\n");
		else
		{
			ra_cnt++;
			rotate(stack_a, "ra\n");
		}
	}
	return (ra_cnt);
}

int	get_limits(t_list *limits, t_list *stack_a)
{
	t_list		*dup;
	int			i_min;
	int			i_max;
	long int	inter_node;

	dup = ft_lstdup(stack_a);
	ft_lstsort(&dup);
	i_min = ft_lstget_idx(dup, (long int)limits->data);
	i_max = ft_lstget_idx(dup, (long int)limits->next->data);
	//printf("\nlimits:%li, %li, imin: %i, imax: %i\n", (long)limits->data, (long)limits->next->data, i_min, i_max);

	if (i_max - i_min > 10 || (i_min == 0 && i_max == (ft_lstsize(stack_a) - 1)))
	{
		i_max = i_min + (i_max - i_min) / 2 + 1;
		inter_node = ft_lstget_data(dup, i_max);
		ft_lstadd_next(limits, ft_lstnew((void *)inter_node));
		//printf("\nlimits:%li, %li, imin: %i, imax: %i, int_node: %li\n", (long)limits->data, (long)limits->next->data, i_min, i_max, inter_node);
	}
	ft_lstclear(&dup, ft_lstdel_int);
	//printf("\n%i\n", i_max - i_min);
	return (i_max - i_min);
}

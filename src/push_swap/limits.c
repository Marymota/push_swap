#include "push_swap.h"

int	get_limits(t_list *limits, t_list *stack_a)
{
	t_list		*dup;
	int			i_min;
	int			i_max;
	int			len;
	long int	inter_node;

	dup = ft_lstdup(stack_a);
	ft_lstsort(&dup);
	i_min = ft_lstget_idx(dup, (long int)limits->data);
	i_max = ft_lstget_idx(dup, (long int)limits->next->data);
	len = ft_lstsize(stack_a);
	if (i_max - i_min > 20 || (i_min == 0 && i_max == len - 1))
	{
		i_max = i_min + (i_max - i_min) / 2 + 1;
		inter_node = ft_lstget_data(dup, i_max);
		ft_lstadd_next(limits, ft_lstnew((void *)inter_node));
	}
	ft_lstclear(&dup, ft_lstdel_int);
	return (i_max - i_min);
}

void	merge_btwn_limits(t_list **stack_a, t_list **stack_b, \
t_list **limits, int len)
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

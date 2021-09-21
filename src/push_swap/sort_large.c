#include "push_swap.h"

int is_min_max_closer_to_top(t_list *stack, int min, int max)
{
	int len;
	int i_min;
	int i_max;
	int check;

	len = ft_lstsize(stack);
	i_min = ft_lstget_idx(stack, min);
	i_max = ft_lstget_idx(stack, max);
	if (i_min < i_max)
		check = (i_min < (len - i_max));
	else
		check = (i_max < (len - i_min));
	return (check);
}

int first_node_sorted(t_list *stack_a, t_list *stack_b)
{
	t_list *dup;
	int first;
	int last;
	long int data_last_node;

	data_last_node = (long int)ft_lstlast(stack_a)->data;
	dup = ft_lstdup(stack_a);
	ft_lstadd_back(&dup, ft_lstdup(stack_b));
	ft_lstsort(&dup);
	first = ft_lstget_idx(dup, (long int)stack_a->data);
	last = ft_lstget_idx(dup, data_last_node);
	ft_lstclear(&dup, ft_lstdel_int);
	if (last == (first - 1) && ft_lstsize(stack_a) > last)
		return (1);
	else
		return (0); 
}

void	rotate_until_sorted(t_list **stack)
{
	int min;
	int half_len;
	int index;

	min = ft_lstget_min(*stack);
	half_len = ft_lstsize(*stack) / 2;
	index = ft_lstget_idx(*stack, (long int)min);
	if(index < half_len)
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


void	merge_b_into_a_partitioning(t_list **stack_a, t_list **stack_b, t_list **partitions, int len)
{
	int curr_len;
	int tmp;

	tmp = 0;
	if (len == 0 || !(*stack_b))
		return ;
	ft_lstadd_front(partitions, ft_lstnew((void *)ft_lstget_median(*stack_b)));
	curr_len = len;
	while (curr_len > len / 2 && *stack_b)
	{
		if((long int)(*partitions)->data <= (long int)(*stack_b)->data && curr_len--)
			push(stack_b, stack_a, "pa\n");
		else if((long int)(*stack_b)->data == ft_lstget_min(*stack_b))
		{
			tmp++;
			push(stack_b, stack_a, "pa\n");
			if (*stack_b != 0)
				rotate(stack_a, "ra\n");
		}
		else
			rotate(stack_b, "rb\n");
	}
	merge_b_into_a_partitioning(stack_a, stack_b, partitions, curr_len-tmp);

}

void merge_b_into_a_ordering (t_list **stack_a, t_list **stack_b)
{
	int min;
	int max;

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
			push(stack_b, stack_a,"pa\n");
		else if (is_min_max_closer_to_top(*stack_b, min, max))
			rotate(stack_b, "rb\n");
		else
			reverse_rotate(stack_b, "rrb\n");
	}
}

int split_a(t_list **stack_a, t_list **stack_b, t_list *partitions, int part_len)
{
	int first_split;
	int ra_count;

	first_split = ft_lstsize(*stack_a) / 2 == part_len;
	ra_count= 0;
	while (part_len)
	{
		if ((long int)partitions->data <= (long int)(*stack_a)->data
			&& (long int)(*stack_a)->data < (long int)partitions->next->data)
		{
			part_len--;
			if (first_node_sorted(*stack_a, *stack_b) && !first_split)
				rotate(stack_a, "ra\n");
			else
				push(stack_a, stack_b, "pb\n");
		}
		else if ((long int)(*stack_a)->data < (long int)partitions->data)
			rotate(stack_a, "ra\n");
		else
		{
			ra_count++;
			rotate(stack_a, "ra\n");
		}
	}
	return (ra_count);
}



int get_diff_partitions(t_list *partitions, t_list *stack_a)
{
	t_list *dup;
	int i_min;
	int i_max;
	long int data_inter_node;

	dup = ft_lstdup(stack_a);
	ft_lstsort(&dup);
	i_min = ft_lstget_idx(dup, (long int)partitions->data);
	i_max = ft_lstget_idx(dup, (long int)partitions->next->data);
	if (i_max - i_min > 20 || (i_min == 0 && i_max == (ft_lstsize(stack_a) - 1)))
	{
		i_max = i_min + (i_max - i_min) / 2 + 1;
		data_inter_node = ft_lstget_data(dup, i_max);
		ft_lstadd_next(partitions, ft_lstnew((void *)data_inter_node));
	}
	ft_lstclear(&dup, ft_lstdel_int);
	return (i_max - i_min);
}
#include "push_swap.h"

int main(int argc, char *argv[])
{
	t_list *stack_a;
	t_list *stack_b;

	stack_a = 0;
	stack_b = 0;
	valid_arguments(argv + 1, argc);
	get_stack(&stack_a, &argv[1]);
	if (!ft_lstsorted(stack_a))
		sort(argc, &stack_a, &stack_b);
	ft_exit(0, &stack_a, &stack_b);
	return (0);
}
/*  “get_stack” program
	Adds the arguments from *argv[] to a linked_list
	In the end it will check for duplicated args
*/
void get_stack(t_list **stack, char **argv)
{
	t_list *node;
	long int data;
	int i;

	i = 0;
	while (argv[i])
	{
		data = ft_atoi(argv[i]);
		node = ft_lstnew((void *)data);
		if (!node)
		{
			ft_lstclear(stack, 0);
			exit(EXIT_FAILURE);
		}
		ft_lstadd_back(stack, node);
		++i;
	}
	if (ft_lstcheck_dup(*stack))
	{
		ft_putstr_fd("Error!\n", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
}

void sort(int args, t_list **stack_a, t_list **stack_b)
{
	long int	min;
	long int	max;
	t_list 		*partitions;

	partitions = 0;
	min = (long int)ft_lstget_min(*stack_a);
	max = (long int)ft_lstget_max(*stack_a);
	ft_lstadd_front(&partitions, ft_lstnew((void *)max));
	ft_lstadd_front(&partitions, ft_lstnew((void *)min));
	if (args <= 4)
		sort_small(stack_a, min, max);
	else if (args <= 6)
		sort_medium(stack_a, stack_b, min, max);
	else
		sort_large(stack_a, stack_b, &partitions);
}

void sort_small(t_list **stack, int min, int max)
{
	while (!ft_lstsorted(*stack))
	{
		if ((int)(*stack)->data == max && (int)(*stack)->next->data == min)
			rotate(stack, "ra\n" );
		else if ((int)(*stack)->data == min || (*stack)->data > (*stack)->next->data)
			swap(*stack, "sa\n");
		else
			reverse_rotate(stack, "rra\n");
	}
}

void sort_medium(t_list **stack_a, t_list **stack_b, int min, int max)
{
	while (ft_lstsize(*stack_a) > 3)
	{
		while ((int)(*stack_a)->data != min)
		{
			if ((int)(*stack_a)->next->data != min && (int)(*stack_a)->data != min)
				reverse_rotate(stack_a, "rra\n");
			else
				rotate(stack_a, "ra\n");
		}
		push(stack_a, stack_b, "pb\n");
		min = ft_lstget_min(*stack_a);
	}
	sort_small(stack_a, min, max);
	while (*stack_b)
		push(stack_b, stack_a, "pa\n");
}

void sort_large(t_list **stack_a, t_list **stack_b, t_list **partitions)
{	
	int ra_count;
	int	len_curr_partition;

	if (ft_lstsize(*partitions) == 1)
		return ;

	len_curr_partition = get_diff_partitions(*partitions, *stack_a);
	ra_count = split_a(stack_a, stack_b, *partitions, len_curr_partition);
	if(ft_lstsize(*stack_a) != ft_lstsize(*stack_b) && ft_lstsize(*stack_a) + 1 != ft_lstsize(*stack_b))
	{
		while (ra_count--)
			reverse_rotate(stack_a, "rra\n");
	}
	if (ft_lstsize(*stack_b) <= 20)
	{
		merge_b_into_a_ordering(stack_a, stack_b);
		ft_lstdel_first(partitions, ft_lstdel_int);
	}
	else
	{
		merge_b_into_a_partitioning(stack_a, stack_b, partitions, ft_lstsize(*stack_b));
		ft_lstsort(partitions);
		ft_lstdel_first(partitions, ft_lstdel_int);
	}
	sort_large(stack_a, stack_b, partitions);
	rotate_until_sorted(stack_a);
	ft_lstclear(partitions, ft_lstdel_int);
}

/*  “push_swap” program
• You have to write a program named push_swap which will receive as an argument
the stack_a formatted as a list of integers.
*/
void ft_exit(int exit_code, t_list **stack_a, t_list **stack_b)
{
	if (exit_code == 0)
	{
		ft_lstclear(stack_a, ft_lstdel_int);
		ft_lstclear(stack_b, ft_lstdel_int);
		exit(EXIT_SUCCESS);
	}
	else
	{
		if (exit_code >= 1)
			ft_lstclear(stack_a, ft_lstdel_int);
		if (exit_code >= 2)
			ft_lstclear(stack_b, ft_lstdel_int);
		ft_putstr_fd("Error\n", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
}
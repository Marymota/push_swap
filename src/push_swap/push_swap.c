#include "push_swap.h"
/*  “push_swap” program
• You have to write a program named push_swap which will receive as an argument
the stack_a formatted as a list of integers.
*/

int main(int argc, char *argv[])
{
	t_list *stack_a;
	t_list *stack_b;

	stack_a = 0;
	(void)stack_b;
	valid_arguments(argv + 1, argc);
	get_stack(&stack_a, &argv[1]);
	if (!ft_lstsorted(stack_a))
		printf("KO!\n");
	else
		printf("OK!\n");
	while (stack_a != NULL)
	{
		printf("%i\n", (int)stack_a->data);
		stack_a = stack_a->next;
	}
	return (1);
}

/*  “get_stack” program
	Adds the arguments from *argv[] to a linked_list
	In the end it will check for duplicated args
*/
void get_stack(t_list **stack, char **argv)
{
	t_list *node;
	long data;
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
	if (ft_lstdup(*stack))
	{
		ft_putstr_fd("Error!\n", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
}
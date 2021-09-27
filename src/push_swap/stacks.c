#include "push_swap.h"

void	get_stack(t_list **stack, int argc, char **argv)
{
	t_list		*node;
	long int	data;
	int			i;

	i = 0;
	if (argc < 3)
	{
		ft_putstr_fd("Not enough arguments!\n", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	while (argv[i])
	{
		if (!ft_strisdigit(argv[i]) || !ft_isint(argv[i]))
			ft_exit(1, 0, 0);
		data = ft_atoi(argv[i]);
		node = ft_lstnew((void *)data);
		if (!node)
			ft_exit(1, stack, 0);
		ft_lstadd_back(stack, node);
		++i;
	}
	if (ft_lstcheck_dup(*stack))
		ft_exit(1, stack, 0);
}

void	print_stack(t_list *stack)
{
	t_list	*node;
	int		len;

	len = ft_lstsize(stack);
	node = stack;
	printf("\n----------");
	while (len--)
	{
		printf("\nstack: %li", (long int)node->data);
		node = node->next;
	}
	printf("\n----------\n\n");
}

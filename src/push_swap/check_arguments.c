#include "push_swap.h"

void	get_stack(t_list **stack, char **argv)
{
	t_list		*node;
	long int	data;
	int			i;

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

void	valid_arguments(char **argv, int argc)
{
	if (argc < 3)
	{
		ft_putstr_fd("Not enough arguments!\n", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	else if (error(argv))
	{
		ft_putstr_fd("Error!\n", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
}

int	error(char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		if (!ft_strisdigit(argv[i]) || !ft_isint(argv[i]))
			return (1);
		++i;
	}
	return (0);
}

void	ft_exit(int exit_code, t_list **stack_a, t_list **stack_b)
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

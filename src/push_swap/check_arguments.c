#include "push_swap.h"

/* Prints an error message and Exit's the program if there are not 
enough arguments to be sorted or if there is other type off error
with the arguments
*/
void valid_arguments(char **argv, int argc)
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

/* In case of error, you must display Error followed by a ’\n’ on the standard error.
Errors include for example: some arguments aren’t integers, some arguments are
bigger than an integer, and/or there are duplicates.
*/
int error(char **argv)
{
	int i;

	i = 0;
	while (argv[i])
	{
		if (!ft_strisdigit(argv[i]) || !ft_isint(argv[i]))
			return(1);
		++i;
	}
	return (0);
}

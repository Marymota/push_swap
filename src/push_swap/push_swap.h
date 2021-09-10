
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./../../libft/src/libft.h"
# include <stdio.h>

// push_swap
void get_stack(t_list **stack, char **args);


// check_arguments
int error(char **argv);
void valid_arguments(char **argv, int argc);

#endif

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./../../libft/src/libft.h"
# include <stdio.h>

// push_swap
void get_stack(t_list **stack, char **args);


// check_arguments
int error(char **argv);
void valid_arguments(char **argv, int argc);

//sort
void sort(int args, t_list **stack_a, t_list **stack_b);
void sort_small(t_list **stack, int min, int max);
void sort_medium(t_list **stack_a, t_list **stack_b, int min, int max);

// actions
void swap(t_list *stack);
void rotate(t_list **stack);
void reverse_rotate(t_list **stack);
void push(t_list **stack_src, t_list **stack_dest);


#endif
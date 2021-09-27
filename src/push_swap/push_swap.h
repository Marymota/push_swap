#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./../../libft/src/libft.h"
# include <stdio.h>

// push_swap
void	sort(int args, t_list **stack_a, t_list **stack_b);
void	sort_small(t_list **stack, int min, int max);
void	sort_medium(t_list **stack_a, t_list **stack_b, int min, int max);
void	sort_large(t_list **stack_a, t_list **stack_b, t_list **limits);
// stacks
void	get_stack(t_list **stack, int argc, char **args);
int		error(char **argv);
void	print_stack(t_list *stack);
// actions
void	swap(t_list *stack, char *action);
void	rotate(t_list **stack, char *action);
void	reverse_rotate(t_list **stack, char *action);
void	push(t_list **stack_src, t_list **stack_dest, char *action);
void	rotate_ab(t_list **stack_a, t_list **stack_b);
//sort_large
int		min_max_close_top(t_list *stack, int min, int max);
int		node_next_to_last(t_list *stack_a, t_list *stack_b);
void	rotate_until_sorted(t_list **stack);
void	merge_b_into_a_ordering (t_list **stack_a, t_list **stack_b);
int		split_stack(t_list **stack_a, t_list **stack_b, \
t_list *limits, int lim_len);
//	limits
int		get_limits(t_list *limits, t_list *stack_a);
void	merge_btwn_limits(t_list **stack_a, t_list **stack_b, \
t_list **lim, int len);
#endif
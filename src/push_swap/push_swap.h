#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./../../libft/src/libft.h"
# include <stdio.h>

// push_swap
void	get_stack(t_list **stack, char **args);
// check_arguments
int		error(char **argv);
void	valid_arguments(char **argv, int argc);
//sort
void	sort(int args, t_list **stack_a, t_list **stack_b);
void	sort_small(t_list **stack, int min, int max);
void	sort_medium(t_list **stack_a, t_list **stack_b, int min, int max);
void	sort_large(t_list **stack_a, t_list **stack_b, t_list **limits);
//sort_large
int		is_min_max_closer_to_top(t_list *stack, int min, int max);
int		first_node_sorted(t_list *stack_a, t_list *stack_b);
void	rotate_until_sorted(t_list **stack);
void	merge_btwn_limits(t_list **stack_a, t_list **stack_b, \
t_list **limits, int len);
void	merge_b_into_a_ordering (t_list **stack_a, t_list **stack_b);
int		split_stack(t_list **stack_a, t_list **stack_b, \
t_list *limits, int limits_len);
void	ft_lstadd_next(t_list *lst, t_list *node);
int		get_diff_limits(t_list *limits, t_list *stack_a);
// actions
void	swap(t_list *stack, char *action);
void	rotate(t_list **stack, char *action);
void	reverse_rotate(t_list **stack, char *action);
void	push(t_list **stack_src, t_list **stack_dest, char *action);
void	rotate_ab(t_list **stack_a, t_list **stack_b);
void	ft_exit(int exit_code, t_list **stack_a, t_list **stack_b);

#endif
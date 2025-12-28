/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaktaou <mlaktaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 09:00:07 by mlaktaou          #+#    #+#             */
/*   Updated: 2025/12/25 12:43:06 by mlaktaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

# define ERROR_NUM LONG_MAX

typedef struct t_node
{
	int				value;
	int				index;
	struct t_node	*next;
}	t_node;

t_node	*find_max_node(t_node *stack);
t_node	*fill_linked_list(char **argv, int argc);
int		ft_args_checker(char **argv);
int		ft_atoi(const char *number);
int		find_max_index(t_node *stack);
int		find_min_index(t_node *stack);
int		is_sorted(t_node *stack);
int		get_stack_size(t_node *stack);
int		get_node_index(t_node *stack, t_node *max_node);
int		duplicate_checker(t_node *stack);
int		ft_lstadd_back(t_node **list, char *number);
void	sort_array(int *array, int size);
void	free_stack(t_node **stack);

void	set_index(t_node *stack, int *array, int size);
void	indexing(t_node *stack);
void	chunking(t_node **stack_a, t_node **stack_b);
void	push_back_to_a(t_node **stack_a, t_node **stack_b);

void	push_swap(t_node **stack_a, t_node **stack_b);
void	sort_three(t_node **stack);
void	sort_five(t_node **stack_a, t_node **stack_b);
void	sort_n_items(t_node **stack_a, t_node **stack_b);

void	sa(t_node **stack_a, int print);
void	sb(t_node **stack_b, int print);
void	ss(t_node **stack_a, t_node **stack_b);

void	pa(t_node **stack_a, t_node **stack_b);
void	pb(t_node **stack_a, t_node **stack_b);

void	ra(t_node **stack_a, int print);
void	rb(t_node **stack_b, int print);
void	rr(t_node **stack_a, t_node **stack_b);

void	rra(t_node **stack_a, int print);
void	rrb(t_node **stack_b, int print);
void	rrr(t_node **stack_a, t_node **stack_b);

#endif
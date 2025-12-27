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

#ifndef PUSH_SWAP
# define PUSH_SWAP

# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

# define ERROR_NUM LONG_MAX

typedef struct t_node{
	int	value;
	int	index;
	struct stack	*next;
}	s_node;

int	ft_args_checker(char *arg);
int	ft_atoi(const char *number);
int	find_max_index(s_node *stack);
int	find_min_index(s_node *stack);
int	is_sorted(s_node *stack);
int	get_stack_size(s_node *stack);
int	get_node_index(s_node *stack, s_node *max_node);
int	duplicate_checker(s_node *stack);
void	ft_lstadd_back(s_node **lst, char *content);
void	sort_array(int *array, int size);
s_node	*find_max_node(s_node *stack);
s_node	*fill_linked_list(char **argv, int argc);
s_node	*ft_lstnew(void *content);
void	free_stack(s_node *stack);

void	set_index(s_node *stack, int *array, int size);
void	indexing(s_node *stack);
void	chunking(s_node **stack_a, s_node **stack_b);
void	push_back_to_a(s_node **stack_a, s_node **stack_b);

void    push_swap(s_node **stack_a, s_node **stack_b);
void	sort_three(s_node **stack);
void	sort_five(s_node **stack_a, s_node **stack_b);
void	sort_n_items(s_node **stack_a, s_node **stack_b);

void	sa(s_node **stack_a, int print);
void	sb(s_node **stack_b, int print);
void	ss(s_node **stack_a, s_node **stack_b);

void	pa(s_node **stack_a, s_node **stack_b);
void	pb(s_node **stack_a, s_node **stack_b);

void	ra(s_node **stack_a, int print);
void	rb(s_node **stack_b, int print);
void	rr(s_node **stack_a, s_node **stack_b);

void	rra(s_node **stack_a, int print);
void	rrb(s_node **stack_b, int print);
void	rrr(s_node **stack_a, s_node **stack_b);

# endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algorithm.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaktaou <mlaktaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 07:16:13 by mlaktaou          #+#    #+#             */
/*   Updated: 2025/12/26 07:16:13 by mlaktaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	set_index(t_node *stack, int *array, int size)
{
	int		i;
	t_node	*current;

	current = stack;
	while (current != NULL)
	{
		i = 0;
		while (i < size)
		{
			if (array[i] == current -> value)
				current -> index = i;
			i++;
		}
		current = current -> next;
	}
}

int	indexing(t_node *stack)
{
	int		*array;
	int		size;
	int		i;
	t_node	*current;

	current = stack;
	size = get_stack_size(stack);
	array = malloc(size * sizeof(int));
	if (!array)
		return (0);
	i = 0;
	while (i < size && current != NULL)
	{
		array[i] = current -> value;
		current = current -> next;
		i++;
	}
	sort_array(array, size);
	set_index(stack, array, size);
	free(array);
	return (1);
}

void	chunking(t_node **stack_a, t_node **stack_b)
{
	int (i), (range), (size);
	i = 0;
	size = get_stack_size(*stack_a);
	if (size <= 100)
		range = 15;
	else if (size <= 500)
		range = 30;
	while ((*stack_a) != NULL)
	{
		if ((*stack_a)-> index <= i)
		{
			pb(stack_a, stack_b, 1);
			i++;
		}
		else if ((*stack_a)-> index <= (range + i))
		{
			pb(stack_a, stack_b, 1);
			rb(stack_b, 1);
			i++;
		}
		else
			ra(stack_a, 1);
	}
}

void	push_back_to_a(t_node **stack_a, t_node **stack_b)
{
	t_node	*max_node;
	int		max_node_index;
	int		size;

	while (*stack_b != NULL)
	{
		size = get_stack_size(*stack_b);
		max_node = find_max_node(*stack_b);
		max_node_index = get_node_index(*stack_b, max_node);
		while (*stack_b != max_node)
		{
			if (!max_node)
				return ;
			if (max_node_index <= size / 2)
				rb(stack_b, 1);
			else
				rrb(stack_b, 1);
		}
		pa(stack_a, stack_b, 1);
	}
}

void	sort_n_items(t_node **stack_a, t_node **stack_b)
{
	if (!indexing(*stack_a))
		return ;
	chunking(stack_a, stack_b);
	push_back_to_a(stack_a, stack_b);
}

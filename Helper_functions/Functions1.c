/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Functions1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaktaou <mlaktaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 09:36:42 by mlaktaou          #+#    #+#             */
/*   Updated: 2025/12/27 09:36:42 by mlaktaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

s_node	*find_max_node(s_node *stack)
{
	s_node	*current;
	s_node *max_node;
	int	max_index;

	current = stack;
	max_index = current -> index;
	max_node = stack;
	while (current != NULL)
	{
		if (current -> index > max_index)
		{
			max_index = current -> index;
			max_node = current;
		}
		current = current -> next;
	}
	return (max_node);
}

int	get_node_index(s_node *stack, s_node *max_node)
{
	s_node *current;
	int	index;

	current = stack;
	index = 0;
	while (current != NULL)
	{
		if (current == max_node)
			return (index);
		index++;
		current = current -> next;		
	}
	return (-1);
}

int	find_max_index(s_node *stack)
{
	s_node	*current;
	int	max_index;
	int	curr_index;
	int	max_value;

	current = stack;
	max_value = current -> value;
	max_index = 0;
	curr_index = 0;
	while (current != NULL)
	{
		if (current -> value > max_value)
		{
			max_value = current -> value;
			max_index = curr_index;
		}
		current = current -> next;
		curr_index++;
	}
	return (max_index);
}

int	find_min_index(s_node *stack)
{
	s_node	*current;
	int	min_index;
	int	curr_index;
	int	min_value;

	current = stack;
	min_value = current -> value;
	min_index = 0;
	curr_index = 0;
	while (current != NULL)
	{
		if (current -> value < min_value)
		{
			min_value = current -> value;
			min_index = curr_index;
		}
		current = current -> next;
		curr_index++;
	}
	return (min_index);
}

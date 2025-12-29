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

t_node	*find_max_node(t_node *stack)
{
	t_node	*current;
	t_node	*max_node;
	int		max_index;

	if (!stack)
		return (NULL);
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

int	get_node_index(t_node *stack, t_node *max_node)
{
	t_node	*current;
	int		index;

	if (!stack || !max_node)
		return (0);
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

int	find_max_index(t_node *stack)
{
	t_node	*current;
	int		max_index;
	int		curr_index;
	int		max_value;

	if (!stack)
		return (0);
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

int	find_min_index(t_node *stack)
{
	t_node	*current;
	int		min_index;
	int		curr_index;
	int		min_value;

	if (!stack)
		return (0);
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

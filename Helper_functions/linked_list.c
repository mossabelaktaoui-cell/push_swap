/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Functions2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaktaou <mlaktaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 09:36:50 by mlaktaou          #+#    #+#             */
/*   Updated: 2025/12/27 09:36:50 by mlaktaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_node	*fill_linked_list(char **argv, int argc)
{
	t_node	*stack;
	int		i;

	i = 1;
	stack = NULL;
	while (i < argc)
	{
		if (!ft_lstadd_back(&stack, argv[i]))
			return (NULL);
		i++;
	}
	return (stack);
}

int	get_stack_size(t_node *stack)
{
	t_node	*current;
	int		count;

	current = stack;
	count = 0;
	while (current != NULL)
	{
		count++;
		current = current -> next;
	}
	return (count);
}

int	ft_lstadd_back(t_node **list, char *number)
{
	t_node	*new_node;
	t_node	*current;
	int		value;

	if (!list || !number)
		return (0);
	new_node = malloc(sizeof(t_node));
	if (!new_node)
		return (0);
	value = ft_atoi(number);
	if (value == ERROR_NUM)
		return (0);
	new_node -> value = value;
	new_node -> next = NULL;
	if (*list == NULL)
		*list = new_node;
	else
	{
		current = *list;
		while (current -> next != NULL)
			current = current -> next;
		current -> next = new_node;
	}
	return (1);
}

void	free_stack(t_node **stack)
{
	t_node	*current;
	t_node	*tmp;

	if (!stack || !*stack)
		return ;
	current = *stack;
	while (current != NULL)
	{
		tmp = current->next;
		free(current);
		current = tmp;
	}
	*stack = NULL;
}

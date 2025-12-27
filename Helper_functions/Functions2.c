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

#include "push_swap.h"

s_node	*fill_linked_list(char **argv, int argc)
{
	s_node	*stack;
	int	i;

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

int	get_stack_size(s_node *stack)
{
	s_node	*current;
	int	count;

	current = stack;
	count = 0;
	while (current != NULL)
	{
		count++;
		current = current -> next;
	}
	return (count);	
}

s_node	*ft_lstnew(void *value)
{
	s_node	*node;

	node = malloc(sizeof(s_node));
	if (!node)
		return (NULL);
	node -> value = value;
	node -> next = NULL;
	return (node);
}

int	ft_lstadd_back(s_node **list, char *number)
{
	s_node	*new_node;
	s_node	*current;
	int	value;

	if (!list || !number || !ft_args_checker(number))
		return (0);
	new_node = malloc(sizeof(s_node));
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

void	free_stack(s_node **stack)
{
	s_node	*current;
	s_node	*tmp;

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
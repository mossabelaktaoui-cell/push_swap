/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_operations.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaktaou <mlaktaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 09:19:30 by mlaktaou          #+#    #+#             */
/*   Updated: 2025/12/27 09:19:30 by mlaktaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(s_node **stack_a, int print)
{
	s_node	*current;

	if (*stack_a && (*stack_a) -> next)
	{
		current = *stack_a;
		while (current -> next -> next != NULL)
			current = current -> next;
		current -> next -> next = *stack_a;
		*stack_a = current -> next;
		current -> next = NULL;		
		if (print)
			write(1, "rra\n", 4);
	}
}

void	rrb(s_node **stack_b, int print)
{
	s_node	*current;

	if (*stack_b && (*stack_b) -> next)
	{
		current = *stack_b;
		while (current -> next -> next != NULL)
			current = current -> next;
		current -> next -> next = *stack_b;
		*stack_b = current -> next;
		current -> next = NULL;		
		if (print)
			write(1, "rrb\n", 4);
	}
}

void	rrr(s_node **stack_a, s_node **stack_b)
{
	rra(stack_a, 0);
	rrb(stack_b, 0);
	if ((*stack_a && (*stack_a) -> next) || (*stack_b && (*stack_b) -> next))
		write(1, "rrr\n", 4);
}

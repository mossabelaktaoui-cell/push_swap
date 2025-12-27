/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaktaou <mlaktaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 09:16:48 by mlaktaou          #+#    #+#             */
/*   Updated: 2025/12/27 09:16:48 by mlaktaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sa(s_node **stack_a, int print)
{
	s_node	*first;
	s_node	*second;

	if (*stack_a && (*stack_a)->next)
        {
		first = *stack_a;
		second = (*stack_a)->next;
		first->next = second->next;
		second->next = first;
		*stack_a = second;
		if (print)
			write(1, "sa\n", 3);
	}
}

void sb(s_node **stack_b, int print)
{
	s_node	*first;
	s_node	*second;

	if (*stack_b && (*stack_b)->next)
	{
		first = *stack_b;
		second = (*stack_b)->next;
		first->next = second->next;
		second->next = first;
		*stack_b = second;
		if (print)
			write(1, "sb\n", 3);
	}
}

void	ss(s_node **stack_a, s_node **stack_b)
{
	sa(stack_a, 0);
	sb(stack_b, 0);
	if ((*stack_a && (*stack_a)->next) || (*stack_b && (*stack_b)->next))
		write(1, "ss\n", 3);	
}

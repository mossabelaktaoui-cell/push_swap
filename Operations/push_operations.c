/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaktaou <mlaktaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 09:17:40 by mlaktaou          #+#    #+#             */
/*   Updated: 2025/12/27 09:17:40 by mlaktaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(s_node **stack_a, s_node **stack_b)
{
	s_node	*tmp;

	if (*stack_b)
	{
		tmp = *stack_b;
		*stack_b = (*stack_b) -> next;
		tmp -> next = *stack_a;
		*stack_a = tmp;
		write(1, "pa\n", 3);
	}
}

void	pb(s_node **stack_a, s_node **stack_b)
{
	s_node	*tmp;

	if (*stack_a)
	{
		tmp = *stack_a;
		*stack_a = (*stack_a) -> next;
		tmp -> next = *stack_b;
		*stack_b = tmp;
		write(1, "pb\n", 3);
	}
}

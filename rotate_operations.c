/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaktaou <mlaktaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 09:18:44 by mlaktaou          #+#    #+#             */
/*   Updated: 2025/12/27 09:18:44 by mlaktaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_node **stack_a, int print)
{
	t_node	*tmp;
	t_node	*curr;

	if (*stack_a && (*stack_a)-> next)
	{
		tmp = *stack_a;
		*stack_a = (*stack_a)-> next;
		curr = *stack_a;
		while (curr -> next != NULL)
			curr = curr -> next;
		curr -> next = tmp;
		tmp -> next = NULL;
		if (print)
			write(1, "ra\n", 3);
	}
}

void	rb(t_node **stack_b, int print)
{
	t_node	*tmp;
	t_node	*curr;

	if (*stack_b && (*stack_b)-> next)
	{
		tmp = *stack_b;
		*stack_b = (*stack_b)-> next;
		curr = *stack_b;
		while (curr -> next != NULL)
			curr = curr -> next;
		curr -> next = tmp;
		tmp -> next = NULL;
		if (print)
			write(1, "rb\n", 3);
	}
}

void	rr(t_node **stack_a, t_node **stack_b, int print)
{
	ra(stack_a, 0);
	rb(stack_b, 0);
	if (((*stack_a && (*stack_a)-> next) || (*stack_b && (*stack_b)-> next))
	&& print)
		write(1, "rr\n", 3);
}

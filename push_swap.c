/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaktaou <mlaktaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 10:15:41 by mlaktaou          #+#    #+#             */
/*   Updated: 2025/12/25 12:54:55 by mlaktaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(t_node **stack_a, t_node **stack_b)
{
	int	size;

	size = get_stack_size(*stack_a);
	if (size <= 1 || is_sorted(*stack_a))
		return ;
	if (size == 2)
		sa(stack_a, 1);
	else if (size == 3)
		sort_three(stack_a);
	else if (size <= 5)
		sort_five(stack_a, stack_b);
	else
		sort_n_items(stack_a, stack_b);
}

int	main(int argc, char **argv)
{
	t_node	*stack_a;
	t_node	*stack_b;

	if (argc < 2 || (argc == 2 && !argv[1][0]))
		return (0);
	stack_a = handle_input(argc, argv);
	if (!stack_a)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	stack_b = NULL;
	push_swap(&stack_a, &stack_b);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}


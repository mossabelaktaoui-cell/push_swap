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

void    push_swap(s_node **stack_a, s_node **stack_b)
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
	s_node	*stack_a;
	s_node	*stack_b;

	if (argc < 2)
        	return (0);
	if (!ft_args_checker(argv))
	{
		write(2, "Error\n", 6);
		return (1);
	}
	stack_a = fill_linked_list(argv, argc);
	if (!stack_a || !duplicate_checker(stack_a))
	{
		write(2, "Error\n", 6);
		if (stack_a)
			free_stack(&stack_a);
		return (1);
	}
	stack_b = NULL;
	push_swap(&stack_a, &stack_b);
	free_stack(&stack_a);
	free_stack(&stack_b);
}

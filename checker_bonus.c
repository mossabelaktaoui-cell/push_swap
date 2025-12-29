/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaktaou <mlaktaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 04:22:54 by mlaktaou          #+#    #+#             */
/*   Updated: 2025/12/29 04:22:54 by mlaktaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "get_next_line.h"

int	operation_selector(t_node **stack_a, t_node **stack_b, char *line)
{
	if (strcmp(line, "sa\n") == 0)
		sa(stack_a, 0);
	else if (strcmp(line, "sb\n") == 0)
		sb(stack_b, 0);
	else if (strcmp(line, "ss\n") == 0)
		ss(stack_b, stack_a, 0);
	else if (strcmp(line, "ra\n") == 0)
		ra(stack_a, 0);
	else if (strcmp(line, "rb\n") == 0)
		rb(stack_b, 0);
	else if (strcmp(line, "rr\n") == 0)
		rr(stack_b, stack_a, 0);
	else if (strcmp(line, "rra\n") == 0)
		rra(stack_a, 0);
	else if (strcmp(line, "rrb\n") == 0)
		rrb(stack_b, 0);
	else if (strcmp(line, "rrr\n") == 0)
		rrr(stack_b, stack_a, 0);
	else if (strcmp(line, "pa\n") == 0)
		pa(stack_a, stack_b, 0);
	else if (strcmp(line, "pb\n") == 0)
		pb(stack_a, stack_b, 0);
	else
		return (write(2, "Error\n", 6), 0);
	return (1);
}

void	checker(t_node **stack_a, t_node **stack_b)
{
	char	*line;

	while (1)
	{
		line = get_next_line(0);
		if (!line)
			break ;
		if (!operation_selector(stack_a, stack_b, line))
		{
			free(line);
			exit(1);
		}
		free(line);
	}
	if (is_sorted(*stack_a) && *stack_b == NULL)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
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
	checker(&stack_a, &stack_b);
	free_stack(&stack_b);
	free_stack(&stack_b);
	return (0);
}
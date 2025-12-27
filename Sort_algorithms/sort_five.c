/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaktaou <mlaktaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 09:38:13 by mlaktaou          #+#    #+#             */
/*   Updated: 2025/12/27 09:38:13 by mlaktaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_five(s_node **stack_a, s_node **stack_b)
{
	int	min_index;
	int	size;

	if(is_sorted(*stack_a))
		return ;
	while (get_stack_size(*stack_a) > 3)
	{
		min_index = find_min_index(*stack_a);
		size = get_stack_size(*stack_a);
		if (min_index == 0)
			pb(stack_a, stack_b);
		else if (min_index <= size / 2)
			ra(stack_a, 1);
		else
			rra(stack_a, 1);
	}
	sort_three(stack_a);
	pa(stack_a, stack_b);
	pa(stack_a, stack_b);
}

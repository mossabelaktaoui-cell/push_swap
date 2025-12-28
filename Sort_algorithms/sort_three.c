/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaktaou <mlaktaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 09:37:47 by mlaktaou          #+#    #+#             */
/*   Updated: 2025/12/27 09:37:47 by mlaktaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_three(t_node **stack)
{
	int	max_index;

	if (is_sorted(*stack))
		return ;
	max_index = find_max_index(*stack);
	if (max_index == 0)
		ra(stack, 1);
	else if (max_index == 1)
		rra(stack, 1);
	if ((*stack)-> value > (*stack)-> next -> value)
		sa(stack, 1);
}

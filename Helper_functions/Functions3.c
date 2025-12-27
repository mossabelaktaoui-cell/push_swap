/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Functions3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaktaou <mlaktaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 09:36:57 by mlaktaou          #+#    #+#             */
/*   Updated: 2025/12/27 09:36:57 by mlaktaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi(const char *number)
{
	int		i;
	int		sign;
	long	result;

	result = 0;
	sign = 1;
	i = 0;
	if (number[i] == '-' || number[i] == '+')
	{
		if (number[i] == '-')
			sign = -1;
		i++;
	}
	while (number[i] >= '0' && number[i] <= '9')
	{
		result = (result * 10) + (number[i] - '0');
		if ((result > 2147483647 && sign == 1) || (result > 2147483648 && sign == -1))
			return (write(2, "Error\n", 6), ERROR_NUM);
		i++;
	}
	result *= sign;
	if (result > 2147483647 || result < -2147483648)
			return (write(2, "Error\n", 6), ERROR_NUM);
	return (result);
}

int	ft_args_checker(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		if (argv[i][j] == '+' || argv[i][j] == '-')
			j++;
		if (argv[i][j] == '\0')
			return (0);
		while (argv[i][j])
		{
			if (argv[i][j] < '0' || argv[i][j] > '9')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	duplicate_checker(s_node *stack)
{
	s_node	*checker;
	s_node	*current;

	checker = stack;
	while (checker != NULL)
	{
		current = checker -> next;
		while (current != NULL)
		{
			if (checker -> value == current -> value)
				return (0);
			current = current -> next;
		}
		checker = checker -> next;
	}
	return (1);
}

int	is_sorted(s_node *stack)
{
	s_node	*current;
	s_node	*next;

	current = stack;
	while (current != NULL && current -> next != NULL)
	{
		next = current -> next;
		if (current -> value > next -> value)
			return (0);
		current = current -> next;
	}
	return (1);
}

void	sort_array(int *array, int size)
{
	int	i;
	int	j;
	int	tmp;
	
	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (array[i] > array[j])
			{
				tmp = array[i];
				array[i] = array[j];
				array[j] = tmp;
			}
			j++;
		}
		i++;
	}
}

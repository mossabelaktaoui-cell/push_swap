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

#include "../push_swap.h"

int	ft_atoi(const char *number)
{
	int			i;
	int			sign;
	long long	result;

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
		if ((result > INT_MAX && sign == 1)
			|| (result > 2147483648L && sign == -1))
			return (ERROR_NUM);
		i++;
	}
	result *= sign;
	if (result > INT_MAX || result < -2147483648L)
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

int	duplicate_checker(t_node *stack)
{
	t_node	*checker;
	t_node	*current;

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

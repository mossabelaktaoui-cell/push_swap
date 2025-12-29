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

long	ft_atoi(const char *number)
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
		return (ERROR_NUM);
	return (result);
}

int	ft_args_checker(char **numbers_list)
{
	int	i;
	int	j;

	i = 0;
	while (numbers_list[i])
	{
		j = 0;
		if (numbers_list[i][j] == '+' || numbers_list[i][j] == '-')
			j++;
		if (numbers_list[i][j] == '\0')
			return (0);
		while (numbers_list[i][j])
		{
			if (numbers_list[i][j] < '0' || numbers_list[i][j] > '9')
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

t_node	*handle_input(int argc, char **argv)
{
	char	**numbers_list;
	t_node	*stack;

	if (argc == 2)
		numbers_list = ft_split(argv[1], ' ');
	else
		numbers_list = argv + 1;
	if (!numbers_list || !ft_args_checker(numbers_list))
	{
		if (numbers_list != argv + 1)
			free_array(numbers_list);
		return (NULL);
	}
	stack = fill_linked_list(numbers_list);
	if (numbers_list != argv + 1)
		free_array(numbers_list);
	if (!stack || !duplicate_checker(stack))
		return (free_stack(&stack), NULL);
	return (stack);
}

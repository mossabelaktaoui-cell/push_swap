/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaktaou <mlaktaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 12:21:29 by mlaktaou          #+#    #+#             */
/*   Updated: 2025/11/16 12:22:20 by mlaktaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	find_newline(char *buffer)
{
	int	i;

	i = 0;
	if (!buffer)
		return (0);
	while (buffer[i])
	{
		if (buffer[i] == '\n')
			return (i + 1);
		i++;
	}
	return (0);
}

int	ft_strlen_until(char *str, char c)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i] && str[i] != c)
		i++;
	if (str[i] == '\n')
		i++;
	return (i);
}

char	*ft_strdup(char *s)
{
	int		i;
	char	*res;

	if (!s)
		return (NULL);
	i = ft_strlen_until(s, '\0');
	res = malloc(i + 1);
	if (!res)
		return (NULL);
	i = 0;
	while (s[i])
	{
		res[i] = s[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

int	ft_strjoin(char **s1, char *s2)
{
	char	*result;
	int		i;
	int		j;

	if (!*s1 && !s2)
		return (0);
	if (*s1 && !s2)
		return (1);
	if (!*s1 && s2)
		return (*s1 = ft_strdup(s2), *s1 != NULL);
	result = malloc(ft_strlen_until(*s1, '\0') + ft_strlen_until(s2, '\0') + 1);
	if (!result)
		return (0);
	i = 0;
	while ((*s1)[i])
	{
		result[i] = (*s1)[i];
		i++;
	}
	j = 0;
	while (s2[j])
		result[i++] = s2[j++];
	result[i] = '\0';
	free(*s1);
	return (*s1 = result, 1);
}

int	read_and_check(int fd, char **buffer, char **storage)
{
	int	read_return;

	read_return = read(fd, *buffer, BUFFER_SIZE);
	if (read_return == -1)
	{
		free(*storage);
		free(*buffer);
		*buffer = NULL;
		*storage = NULL;
		return (-1);
	}
	if (read_return == 0)
	{
		free(*buffer);
		*buffer = NULL;
		if (!*storage || (*storage)[0] == '\0')
		{
			free(*storage);
			*storage = NULL;
		}
		return (0);
	}
	(*buffer)[read_return] = '\0';
	return (read_return);
}

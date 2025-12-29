/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaktaou <mlaktaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 12:21:25 by mlaktaou          #+#    #+#             */
/*   Updated: 2025/11/16 12:31:36 by mlaktaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*extract_line(char *storage)
{
	char	*line;
	int		i;

	if (!storage || !storage[0])
		return (NULL);
	i = 0;
	line = malloc(ft_strlen_until(storage, '\n') + 1);
	if (!line)
		return (NULL);
	while (storage[i] && storage[i] != '\n')
	{
		line[i] = storage[i];
		i++;
	}
	if (storage[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

int	clean_storage(char **storage)
{
	char	*new_storage;
	int		newline_indx;
	int		i;

	if (!storage || !*storage)
		return (0);
	i = 0;
	newline_indx = ft_strlen_until(*storage, '\n');
	new_storage = malloc(ft_strlen_until(*storage, '\0') - newline_indx + 1);
	if (!new_storage)
		return (free(*storage), *storage = NULL, 0);
	while ((*storage)[newline_indx])
		new_storage[i++] = (*storage)[newline_indx++];
	new_storage[i] = '\0';
	free(*storage);
	*storage = new_storage;
	if ((*storage)[0] == '\0')
	{
		free(*storage);
		*storage = NULL;
	}
	return (1);
}

int	read_and_append(int fd, char **storage)
{
	char	*buffer;
	int		read_return;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (0);
	buffer[0] = '\0';
	while (!find_newline(buffer))
	{
		read_return = read_and_check(fd, &buffer, storage);
		if (read_return == -1)
			return (0);
		if (read_return == 0)
			return (1);
		if (!ft_strjoin(storage, buffer))
			return (free(buffer), 0);
	}
	free(buffer);
	return (read_return);
}

char	*get_next_line(int fd)
{
	static char	*storage;
	char		*result;

	if (fd < 0 || fd >= 1024 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!read_and_append(fd, &storage))
		return (NULL);
	if (!storage || storage[0] == '\0')
		return (NULL);
	result = extract_line(storage);
	if (!result)
		return (free(storage), storage = NULL, NULL);
	if (!clean_storage(&storage))
		return (free(result), NULL);
	return (result);
}

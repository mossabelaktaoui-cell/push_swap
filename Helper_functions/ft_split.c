/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaktaou <mlaktaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 16:17:48 by mlaktaou          #+#    #+#             */
/*   Updated: 2025/12/29 02:56:59 by mlaktaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	count_words(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i])
		{
			count++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (count);
}

int	get_word_length(char const *s, char c)
{
	int	i;

	i = 0;
	while (s[i] == c)
		i++;
	while (s[i] != c && s[i])
		i++;
	return (i);
}

char	**fill_array(int words_num, char const *s, char c, char **array)
{
	char	*word;

	int (i), (j), (word_ind);
	i = 0;
	word_ind = 0;
	while (word_ind < words_num)
	{
		while (s[i] == c)
			i++;
		word = malloc((get_word_length(s + i, c) + 1) * sizeof(char));
		if (!word)
			return (NULL);
		j = 0;
		while (j < get_word_length(s + i, c))
		{
			word[j] = s[i + j];
			j++;
		}
		word[j] = '\0';
		array[word_ind] = word;
		i += get_word_length(s + i, c);
		word_ind++;
	}
	array[word_ind] = NULL;
	return (array);
}

void	free_array(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

char	**ft_split(char const *s, char c)
{
	char	**array;
	char	**tmp;
	int		words_num;

	if (!s)
		return (NULL);
	words_num = count_words(s, c);
	array = malloc((words_num + 1) * sizeof(char *));
	if (!array)
		return (NULL);
	tmp = fill_array(words_num, s, c, array);
	if (!tmp)
	{
		free_array(array);
		return (NULL);
	}
	return (array);
}

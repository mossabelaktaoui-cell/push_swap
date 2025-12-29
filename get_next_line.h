/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaktaou <mlaktaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 12:21:20 by mlaktaou          #+#    #+#             */
/*   Updated: 2025/11/16 12:25:09 by mlaktaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*get_next_line(int fd);
char	*ft_strdup(char *s);
char	*extract_line(char *storage);
int		find_newline(char *buffer);
int		ft_strlen_until(char *str, char c);
int		ft_strjoin(char **s1, char *s2);
int		clean_storage(char **storage);
int		read_and_check(int fd, char **buffer, char **storage);
int		read_and_append(int fd, char **storage);

#endif
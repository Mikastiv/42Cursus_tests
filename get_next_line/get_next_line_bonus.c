/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleblanc <mleblanc@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 22:07:54 by mleblanc          #+#    #+#             */
/*   Updated: 2021/05/13 16:32:15 by mleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <unistd.h>
#include <stdlib.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 32
#endif

#define MAX_FD 8192

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

static char	*ft_strchr(const char *s, int c)
{
	while (*s != (unsigned char)c)
	{
		if (*s++ == '\0')
			return (NULL);
	}
	return ((char *)s);
}

static int	read_file(char	**file_buffer, int fd)
{
	char		*read_buffer;
	char		*tmp;
	ssize_t		bytes;

	read_buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!read_buffer)
		return (-1);
	bytes = read(fd, read_buffer, BUFFER_SIZE);
	if (bytes < 0)
		free(read_buffer);
	if (bytes < 0)
		return (-1);
	read_buffer[bytes] = '\0';
	tmp = ft_strjoin(*file_buffer, read_buffer);
	if (!tmp)
		free(read_buffer);
	if (!tmp)
		return (-1);
	free(*file_buffer);
	free(read_buffer);
	*file_buffer = tmp;
	if (bytes < BUFFER_SIZE)
		return (0);
	return (1);
}

static int	get_line(char **buffer, char **line)
{
	char	*tmp;
	char	*newline;

	newline = ft_strchr(*buffer, '\n');
	if (!newline)
		*line = ft_strdup(*buffer);
	else
		*line = ft_substr(*buffer, 0, newline - *buffer);
	if (!*line)
		return (-1);
	if (!newline)
	{
		free(*buffer);
		*buffer = NULL;
		return (0);
	}
	else
	{
		tmp = ft_substr(*buffer, ft_strlen(*line) + 1, BUFFER_SIZE);
		if (!tmp)
			return (-1);
		free(*buffer);
		*buffer = tmp;
		return (1);
	}
}

int	get_next_line(int fd, char **line)
{
	static char	*buffer[MAX_FD] = {NULL};
	int			code;

	if (fd < 0 || fd >= MAX_FD || !line)
		return (-1);
	if (!buffer[fd])
		buffer[fd] = ft_strdup("");
	code = 1;
	while (!ft_strchr(buffer[fd], '\n'))
	{
		code = read_file(&buffer[fd], fd);
		if (code < 1)
			break ;
	}
	if (code < 0)
		return (-1);
	code = get_line(&buffer[fd], line);
	if (code < 0)
		return (-1);
	if (code == 0)
		return (0);
	return (1);
}
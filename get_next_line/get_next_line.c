/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleblanc <mleblanc@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/08 20:11:44 by mleblanc          #+#    #+#             */
/*   Updated: 2021/05/11 19:07:35 by mleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 32
#endif

#define MAX_FD 8192

char	*ft_strchr(const char *s, int c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);

static size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

static int	read_file(char	**file_buffer, int fd)
{
	char		read_buffer[BUFFER_SIZE + 1];
	char		*tmp;
	ssize_t		bytes;

	bytes = read(fd, read_buffer, BUFFER_SIZE);
	if (bytes < 0)
		return (bytes);
	read_buffer[bytes] = '\0';
	tmp = *file_buffer;
	if (!*file_buffer)
		*file_buffer = ft_substr(read_buffer, 0, BUFFER_SIZE);
	else
		*file_buffer = ft_strjoin(*file_buffer, read_buffer);
	if (!*file_buffer)
	{
		*file_buffer = tmp;
		return (-1);
	}
	free(tmp);
	if (bytes > 0)
		return (1);
	return (0);
}

static char	*extract_line(char **file_buffer, size_t nl_index)
{
	char	*tmp;
	char	*line;
	size_t	len;

	tmp = *file_buffer;
	line = ft_substr(*file_buffer, 0, nl_index);
	if (!line)
		return (NULL);
	len = ft_strlen(*file_buffer + nl_index + 1);
	*file_buffer = ft_substr(*file_buffer, nl_index + 1, len);
	if (!*file_buffer)
	{
		*file_buffer = tmp;
		return (NULL);
	}
	free(tmp);
	return (line);
}

static char	*get_line(char **file_buffer, char *newline)
{
	char	*line;

	if (newline)
	{
		line = extract_line(file_buffer, newline - *file_buffer);
		if (!line)
			return (NULL);
	}
	else
	{
		line = ft_substr(*file_buffer, 0, ft_strlen(*file_buffer));
		if (!line)
			return (NULL);
		free(*file_buffer);
		*file_buffer = NULL;
	}
	return (line);
}

int	get_next_line(int fd, char **line)
{
	static char	*file_buffers[MAX_FD] = {};
	char		*newline;
	int			code;

	if (fd < 0 || fd >= MAX_FD || !line)
		return (-1);
	newline = NULL;
	if (file_buffers[fd])
		newline = ft_strchr(file_buffers[fd], '\n');
	code = 1;
	while (!newline)
	{
		code = read_file(&file_buffers[fd], fd);
		if (code < 1)
			break ;
		newline = ft_strchr(file_buffers[fd], '\n');
	}
	if (code < 0)
		return (code);
	*line = get_line(&file_buffers[fd], newline);
	if (!*line)
		return (-1);
	if (code == 0 && ft_strlen(*line) == 0)
		return (0);
	return (1);
}
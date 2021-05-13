/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleblanc <mleblanc@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 12:35:21 by mleblanc          #+#    #+#             */
/*   Updated: 2021/05/13 12:45:37 by mleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>

static size_t	ft_strnlen(const char *s, size_t maxlen)
{
	size_t	len;

	len = 0;
	while (len < maxlen)
	{
		if (!s[len])
			break ;
		len++;
	}
	return (len);
}

static size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	srclen;
	size_t	n;

	srclen = ft_strlen(src);
	if (srclen + 1 < dstsize)
	{
		n = srclen + 1;
		while (n-- > 0)
			*dst++ = *src++;
	}
	else if (dstsize != 0)
	{
		n = dstsize - 1;
		while (n-- > 0)
			*dst++ = *src++;
		*dst = '\0';
	}
	return (srclen);
}

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	size_t	newlen;
	size_t	strlen;
	char	*substr;

	strlen = ft_strlen(s);
	newlen = 0;
	if (strlen > start)
		newlen = ft_strnlen(s + start, len);
	else
		start = strlen;
	substr = (char *)malloc((newlen + 1) * sizeof(char));
	if (!substr)
		return (NULL);
	ft_strlcpy(substr, s + start, (newlen + 1) * sizeof(char));
	return (substr);
}

char	*ft_strdup(const char *s1)
{
	size_t	size;
	size_t	i;
	char	*s2;

	size = ft_strlen(s1) + 1;
	s2 = (char *)malloc(size * sizeof(char));
	if (!s2)
		return (NULL);
	i = 0;
	while (i < size)
	{
		s2[i] = s1[i];
		i++;
	}
	return (s2);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*newstr;
	char	*ptr;
	size_t	s1_len;
	size_t	s2_len;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	newstr = (char *)malloc((s1_len + s2_len + 1) * sizeof(char));
	if (!newstr)
		return (NULL);
	ptr = newstr;
	while (s1_len-- > 0)
		*ptr++ = *s1++;
	while (s2_len-- > 0)
		*ptr++ = *s2++;
	*ptr = '\0';
	return (newstr);
}

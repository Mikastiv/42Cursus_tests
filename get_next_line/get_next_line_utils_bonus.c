/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleblanc <mleblanc@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/08 20:50:06 by mleblanc          #+#    #+#             */
/*   Updated: 2021/05/12 18:40:49 by mleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

size_t	ft_strnlen(const char *s, size_t maxlen)
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

char	*ft_strchr(const char *s, int c)
{
	while (*s != (unsigned char)c)
	{
		if (*s++ == '\0')
			return (NULL);
	}
	return ((char *)s);
}

static size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	srclen;
	size_t	n;

	srclen = 0;
	while (src[srclen])
		srclen++;
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

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	newlen;
	size_t	strlen;
	char	*substr;

	strlen = 0;
		newlen = 0;
	while (s[strlen])
		strlen++;
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

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*newstr;
	char	*ptr;
	size_t	size;
	size_t	i;

	size = 0;
	i = 0;
	while (s1[i++])
		size++;
	i = 0;
	while (s2[i++])
		size++;
	size++;
	newstr = (char *)malloc(size * sizeof(char));
	if (!newstr)
		return (NULL);
	ptr = newstr;
	while (*s1)
		*ptr++ = *s1++;
	while (*s2)
		*ptr++ = *s2++;
	*ptr = '\0';
	return (newstr);
}

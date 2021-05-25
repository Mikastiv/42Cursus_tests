/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleblanc <mleblanc@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 00:32:01 by mleblanc          #+#    #+#             */
/*   Updated: 2021/05/23 12:16:08 by mleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_numlen(int num, int base)
{
	size_t	len;

	len = 0;
	while (num / base != 0)
	{
		num /= base;
		len++;
	}
	return (len + 1);
}

static void	ft_ntoa(char *buf, int n, const char *base, size_t len)
{
	int	base_len;
	int	i;

	base_len = ft_strlen(base);
	if (n < 0)
		*buf++ = '-';
	while (len > 0)
	{
		i = n % base_len;
		if (i < 0)
			i *= -1;
		buf[--len] = base[i];
		n /= base_len;
	}
}

char	*ft_itoa_base(int n, const char *base)
{
	char	*ret;
	size_t	len;
	size_t	size;
	size_t	base_len;

	base_len = ft_strlen(base);
	len = ft_numlen(n, (int)base_len);
	size = len + 1;
	if (n < 0)
		size += 1;
	ret = (char *)ft_calloc(size, sizeof(char));
	if (!ret)
		return (NULL);
	ft_ntoa(ret, n, base, len);
	return (ret);
}

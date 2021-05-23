/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleblanc <mleblanc@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 01:50:27 by mleblanc          #+#    #+#             */
/*   Updated: 2021/05/16 02:08:40 by mleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_numlen(unsigned int num, unsigned int base)
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

static void	ft_ntoa(char *buf, unsigned int n, const char *base, size_t len)
{
	size_t	base_len;

	base_len = ft_strlen(base);
	while (len > 0)
	{
		buf[--len] = base[n % base_len];
		n /= base_len;
	}
}

char	*ft_utoa_base(unsigned int n, const char *base)
{
	char	*ret;
	size_t	len;
	size_t	base_len;

	base_len = ft_strlen(base);
	len = ft_numlen(n, (unsigned int)base_len);
	ret = (char *)ft_calloc(len + 1, sizeof(char));
	if (!ret)
		return (NULL);
	ft_ntoa(ret, n, base, len);
	return (ret);
}

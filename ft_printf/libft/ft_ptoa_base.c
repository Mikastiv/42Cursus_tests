/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleblanc <mleblanc@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 23:27:35 by mleblanc          #+#    #+#             */
/*   Updated: 2021/05/16 23:32:12 by mleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_numlen(size_t num, size_t base)
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

static void	ft_ntoa(char *buf, size_t n, const char *base, size_t len)
{
	size_t	base_len;

	base_len = ft_strlen(base);
	while (len > 0)
	{
		buf[--len] = base[n % base_len];
		n /= base_len;
	}
}

char	*ft_ptoa_base(void *ptr, const char *base)
{
	char	*ret;
	size_t	len;
	size_t	base_len;

	base_len = ft_strlen(base);
	len = ft_numlen((size_t)ptr, base_len);
	ret = (char *)ft_calloc(len + 1, sizeof(char));
	if (!ret)
		return (NULL);
	ft_ntoa(ret, (size_t)ptr, base, len);
	return (ret);
}

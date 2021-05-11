/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleblanc <mleblanc@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 17:31:45 by mleblanc          #+#    #+#             */
/*   Updated: 2021/05/06 19:12:10 by mleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_numlen(int num)
{
	size_t	len;

	len = 0;
	while (num / 10 != 0)
	{
		num /= 10;
		len++;
	}
	return (len + 1);
}

static void	ft_num_to_ascii(char *buf, long n, size_t len)
{
	if (n < 0)
	{
		*buf = '-';
		n *= -1;
		buf++;
	}
	while (len > 0)
	{
		buf[--len] = '0' + (n % 10);
		n /= 10;
	}
}

char	*ft_itoa(int n)
{
	char	*ret;
	size_t	len;
	size_t	size;

	len = ft_numlen(n);
	size = len + 1;
	if (n < 0)
		size += 1;
	ret = (char *)ft_calloc(size, sizeof(char));
	if (!ret)
		return (NULL);
	ft_num_to_ascii(ret, (long)n, len);
	return (ret);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleblanc <mleblanc@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 16:45:36 by mleblanc          #+#    #+#             */
/*   Updated: 2021/05/22 17:55:21 by mleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "convert_str.h"
#include "flags.h"
#include "libft.h"
#include "utils.h"
#include <limits.h>

#define NULL_STR "(null)"

bool	convert_str(t_pinfo *info)
{
	const char	*str;
	int			len;

	if (!(info->flags & F_PRECISION))
		info->precision = INT_MAX;
	str = va_arg(info->va, char *);
	if (!str)
		str = NULL_STR;
	len = (int)ft_strnlen(str, (size_t)info->precision);
	if (!(info->flags & F_LEFTALIGN))
		add_padding(info, &len, ' ');
	while (*str && info->precision--)
	{
		info->ft_putc(*str++);
		info->count++;
	}
	if (info->flags & F_LEFTALIGN)
		add_padding(info, &len, ' ');
	return (true);
}

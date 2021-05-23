/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleblanc <mleblanc@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 20:36:48 by mleblanc          #+#    #+#             */
/*   Updated: 2021/05/22 21:17:01 by mleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "do_printf.h"
#include "flags.h"
#include "libft.h"
#include "convert.h"
#include "utils.h"
#include <stdbool.h>

static void	get_flags(const char **fmt, t_pinfo *info)
{
	info->flags = 0U;
	while (true)
	{
		if (**fmt == '0')
			info->flags |= F_ZEROPAD;
		else if (**fmt == '-')
			info->flags |= F_LEFTALIGN;
		else
			break ;
		(*fmt)++;
	}
	if (info->flags & F_LEFTALIGN)
		info->flags &= ~F_ZEROPAD;
}

static void	get_width(const char **fmt, t_pinfo *info)
{
	int	arg;

	info->width = 0;
	if (ft_isdigit(**fmt))
		info->width = to_int(fmt);
	else if (**fmt == '*')
	{
		arg = va_arg(info->va, int);
		if (arg < 0)
		{
			info->flags |= F_LEFTALIGN;
			if (info->flags & F_LEFTALIGN)
				info->flags &= ~F_ZEROPAD;
			info->width = -arg;
		}
		else
			info->width = arg;
		(*fmt)++;
	}
}

static void	get_precision(const char **fmt, t_pinfo *info)
{
	info->precision = 0;
	if (**fmt == '.')
	{
		info->flags |= F_PRECISION;
		(*fmt)++;
		if (ft_isdigit(**fmt))
			info->precision = to_int(fmt);
		else if (**fmt == '*')
		{
			info->precision = va_arg(info->va, int);
			if (info->precision < 0)
				info->flags &= ~F_PRECISION;
			(*fmt)++;
		}
	}
}

int	do_printf(const char *fmt, t_pinfo *info)
{
	bool	error;

	error = false;
	info->count = 0;
	while (*fmt)
	{
		if (*fmt != '%')
		{
			info->ft_putc(*fmt++);
			info->count++;
			continue ;
		}
		fmt++;
		get_flags(&fmt, info);
		get_width(&fmt, info);
		get_precision(&fmt, info);
		if (!convert(&fmt, info) || info->count < 0)
			error = true;
	}
	if (error)
		return (-1);
	return (info->count);
}

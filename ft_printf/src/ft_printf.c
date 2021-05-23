/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleblanc <mleblanc@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 19:07:16 by mleblanc          #+#    #+#             */
/*   Updated: 2021/05/18 14:59:29 by mleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "do_printf.h"

void	ft_putchar(char c)
{
	ft_putchar_fd(c, 1);
}

int	ft_printf(const char *format, ...)
{
	t_pinfo	info;
	int		result;

	if (!format)
		return (-1);
	info = (t_pinfo){};
	va_start(info.va, format);
	info.ft_putc = ft_putchar;
	result = do_printf(format, &info);
	va_end(info.va);
	return (result);
}

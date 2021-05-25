/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleblanc <mleblanc@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 19:07:16 by mleblanc          #+#    #+#             */
/*   Updated: 2021/05/23 17:11:09 by mleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "do_printf.h"
#include <unistd.h>

void	ft_putchar(unsigned char c)
{
	write(1, &c, sizeof(unsigned char));
}

void	ft_putwchar(wint_t c)
{
	write(1, &c, sizeof(wint_t));
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
	info.ft_putwc = ft_putwchar;
	result = do_printf(format, &info);
	va_end(info.va);
	return (result);
}

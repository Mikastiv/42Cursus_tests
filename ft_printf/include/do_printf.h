/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleblanc <mleblanc@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 20:37:02 by mleblanc          #+#    #+#             */
/*   Updated: 2021/05/23 17:11:19 by mleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DO_PRINTF_H
# define DO_PRINTF_H

# include <stdarg.h>
# include <wchar.h>

typedef struct s_pinfo
{
	va_list			va;
	unsigned int	flags;
	int				width;
	int				precision;
	int				count;
	void			(*ft_putc)(unsigned char);
	void			(*ft_putwc)(wint_t);
}	t_pinfo;

int	do_printf(const char *fmt, t_pinfo *info);

#endif

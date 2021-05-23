/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleblanc <mleblanc@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 14:10:20 by mleblanc          #+#    #+#             */
/*   Updated: 2021/05/22 18:47:26 by mleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "convert.h"
#include "convert_char.h"
#include "convert_str.h"
#include "convert_ptr.h"
#include "convert_percent.h"
#include "convert_int.h"
#include "convert_uint.h"

bool	convert(const char **fmt, t_pinfo *info)
{
	if (**fmt == 'c' && (*fmt)++)
		return (convert_char(info, (char)va_arg(info->va, int)));
	else if (**fmt == 's' && (*fmt)++)
		return (convert_str(info));
	else if (**fmt == 'p' && (*fmt)++)
		return (convert_ptr(info));
	else if ((**fmt == 'd' || **fmt == 'i') && (*fmt)++)
		return (convert_int(info));
	else if (**fmt == 'u' && (*fmt)++)
		return (convert_uint(info, "0123456789"));
	else if (**fmt == 'x' && (*fmt)++)
		return (convert_uint(info, "0123456789abcdef"));
	else if (**fmt == 'X' && (*fmt)++)
		return (convert_uint(info, "0123456789ABCDEF"));
	else if (**fmt == '%' && (*fmt)++)
		return (convert_percent(info));
	else
		return (convert_char(info, *((*fmt)++)));
}

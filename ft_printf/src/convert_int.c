/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_int.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleblanc <mleblanc@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 16:33:22 by mleblanc          #+#    #+#             */
/*   Updated: 2021/05/24 15:37:37 by mleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "convert_int.h"
#include "flags.h"
#include "libft.h"
#include "utils.h"
#include "convert_num_utils.h"
#include <stdlib.h>
#include <stdbool.h>

static long	get_number(t_pinfo *info)
{
	if (info->flags & F_LONG)
		return (va_arg(info->va, long));
	else
		return ((int)va_arg(info->va, int));
}

static char	*get_prefix(t_pinfo *info, long nb)
{
	if (nb < 0)
		return ("-");
	else if (info->flags & F_PLUS)
		return ("+");
	else if (info->flags & F_SPACE)
		return (" ");
	else
		return (NULL);
}

static char	*convert_to_str(long nb, t_pinfo *info)
{
	if (info->flags & F_LONG)
	{
		if (nb < 0)
			return (ft_ultoa((unsigned long)(0 - nb)));
		return (ft_ultoa((unsigned long)nb));
	}
	else
	{
		if ((int)nb < 0)
			return (ft_utoa((unsigned int)(0 - (int)nb)));
		return (ft_utoa((unsigned int)((int)nb)));
	}
}

static void	print_number(t_pinfo *info, char *str, char *prefix, char pad_char)
{
	if (prefix)
		info->width--;
	if (prefix && pad_char == '0')
		ft_putstr(prefix, info);
	if (!(info->flags & F_LEFTALIGN))
		add_num_padding(info, pad_char);
	if (prefix && pad_char == ' ')
		ft_putstr(prefix, info);
	if (info->flags & F_PRECISION)
		while (info->precision && info->precision-- > 0 && ++info->count)
			info->ft_putc('0');
	ft_putstr(str, info);
	if (info->flags & F_LEFTALIGN)
		add_num_padding(info, pad_char);
}

bool	convert_int(t_pinfo *info)
{
	long	nb;
	char	pad_char;
	char	*str;
	char	*prefix;
	bool	precision_is_0;

	nb = get_number(info);
	str = convert_to_str(nb, info);
	if (info->flags & F_PRECISION)
		info->flags &= ~F_ZEROPAD;
	pad_char = get_pad_char(info);
	prefix = get_prefix(info, nb);
	precision_is_0 = (info->flags & F_PRECISION) && (info->precision == 0);
	if (nb == 0 && precision_is_0)
	{
		add_num_padding(info, ' ');
		return (true);
	}
	if (!str)
		return (false);
	calculate_padding(info, str);
	print_number(info, str, prefix, pad_char);
	free(str);
	return (true);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_uint.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleblanc <mleblanc@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 18:53:44 by mleblanc          #+#    #+#             */
/*   Updated: 2021/05/24 20:38:31 by mleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "convert_uint.h"
#include "flags.h"
#include "libft.h"
#include "utils.h"
#include "convert_num_utils.h"
#include <stdlib.h>

static unsigned long	get_number(t_pinfo *info)
{
	if (info->flags & F_LONG)
		return (va_arg(info->va, unsigned long));
	else
		return ((unsigned long)va_arg(info->va, unsigned int));
}

static int	number_length(unsigned long nb, unsigned long base)
{
	unsigned long	len;

	len = 0;
	while (nb / base != 0)
	{
		nb /= base;
		len++;
	}
	return ((int)(len + 1));
}

static void	adjust_precision(unsigned long nb, t_pinfo *info)
{
	int	len;

	len = number_length(nb, 8) + 1;
	if (info->precision < len)
		info->precision = len;
	info->flags |= F_PRECISION;
}

static void	print_number(t_pinfo *info, char *str, char pad_char, char *prefix)
{
	bool	num_is_0;

	num_is_0 = ft_strncmp(str, "0", 8);
	if (info->flags & F_HASH && num_is_0)
		info->width -= ft_strnlen(prefix, 2);
	if (info->flags & F_HASH && pad_char == '0' && num_is_0)
		ft_putstr(prefix, info);
	if (!(info->flags & F_LEFTALIGN))
		add_num_padding(info, pad_char);
	if (info->flags & F_HASH && pad_char == ' ' && num_is_0)
		ft_putstr(prefix, info);
	if (info->flags & F_PRECISION)
		while (info->precision && info->precision-- > 0 && ++info->count)
			info->ft_putc('0');
	ft_putstr(str, info);
	if (info->flags & F_LEFTALIGN)
		add_num_padding(info, pad_char);
}

bool	convert_uint(t_pinfo *info, char *base, char *prefix, t_convert conv)
{
	unsigned long	nb;
	char			pad_char;
	char			*str;
	bool			precision_is_0;

	nb = get_number(info);
	if (conv == octal && info->flags & F_HASH)
		adjust_precision(nb, info);
	str = ft_ultoa_base(nb, base);
	if (info->flags & F_PRECISION && conv != octal && info->flags & F_HASH)
		info->flags &= ~F_ZEROPAD;
	pad_char = get_pad_char(info);
	precision_is_0 = (info->flags & F_PRECISION) && (info->precision == 0);
	if (nb == 0 && precision_is_0)
	{
		add_num_padding(info, ' ');
		return (true);
	}
	if (!str)
		return (false);
	calculate_padding(info, str);
	print_number(info, str, pad_char, prefix);
	free(str);
	return (true);
}

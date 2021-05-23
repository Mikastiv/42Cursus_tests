/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_uint.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleblanc <mleblanc@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 18:53:44 by mleblanc          #+#    #+#             */
/*   Updated: 2021/05/22 18:01:27 by mleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "convert_uint.h"
#include "flags.h"
#include "libft.h"
#include "utils.h"
#include "convert_num_utils.h"
#include <stdlib.h>

static void	print_number(t_pinfo *info, char *str, char pad_char)
{
	if (!(info->flags & F_LEFTALIGN))
		add_num_padding(info, pad_char);
	if (info->flags & F_PRECISION)
		while (info->precision && info->precision-- > 0 && ++info->count)
			info->ft_putc('0');
	ft_putstr(str, info);
	if (info->flags & F_LEFTALIGN)
		add_num_padding(info, pad_char);
}

bool	convert_uint(t_pinfo *info, char *base)
{
	unsigned int	nb;
	char			pad_char;
	char			*str;
	bool			precision_is_0;

	nb = va_arg(info->va, unsigned int);
	str = ft_utoa_base(nb, base);
	if (info->flags & F_PRECISION)
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
	print_number(info, str, pad_char);
	free(str);
	return (true);
}

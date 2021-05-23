/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_int.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleblanc <mleblanc@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 16:33:22 by mleblanc          #+#    #+#             */
/*   Updated: 2021/05/22 18:01:08 by mleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "convert_int.h"
#include "flags.h"
#include "libft.h"
#include "utils.h"
#include "convert_num_utils.h"
#include <stdlib.h>
#include <stdbool.h>

static char	*convert_to_str(int nb)
{
	if (nb < 0)
		return (ft_ultoa(-((long)nb)));
	return (ft_ultoa((unsigned long)nb));
}

static void	print_number(t_pinfo *info, char *str, int nb, char pad_char)
{
	if (nb < 0 && pad_char == '0')
		ft_putstr("-", info);
	if (!(info->flags & F_LEFTALIGN))
		add_num_padding(info, pad_char);
	if (nb < 0 && pad_char == ' ')
		ft_putstr("-", info);
	if (info->flags & F_PRECISION)
		while (info->precision && info->precision-- > 0 && ++info->count)
			info->ft_putc('0');
	ft_putstr(str, info);
	if (info->flags & F_LEFTALIGN)
		add_num_padding(info, pad_char);
}

bool	convert_int(t_pinfo *info)
{
	int		nb;
	char	pad_char;
	char	*str;
	bool	precision_is_0;

	nb = va_arg(info->va, int);
	str = convert_to_str(nb);
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
	if (nb < 0)
		info->width--;
	print_number(info, str, nb, pad_char);
	free(str);
	return (true);
}

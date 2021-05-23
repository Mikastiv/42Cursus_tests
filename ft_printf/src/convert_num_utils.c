/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_num_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleblanc <mleblanc@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 19:51:18 by mleblanc          #+#    #+#             */
/*   Updated: 2021/05/21 19:53:38 by mleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "convert_num_utils.h"
#include "flags.h"
#include "libft.h"
#include <limits.h>

void	add_num_padding(t_pinfo *info, char c)
{
	while (info->width-- > 0)
	{
		info->ft_putc(c);
		info->count++;
	}
}

void	calculate_padding(t_pinfo *info, char *str)
{
	int	len;

	len = ft_strnlen(str, INT_MAX);
	info->width -= len;
	info->precision -= len;
	if (info->flags & F_PRECISION && info->precision > 0)
		info->width -= info->precision;
}

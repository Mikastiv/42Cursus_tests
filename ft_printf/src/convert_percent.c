/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_percent.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleblanc <mleblanc@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 14:16:52 by mleblanc          #+#    #+#             */
/*   Updated: 2021/05/22 17:55:06 by mleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "convert_percent.h"
#include "flags.h"
#include "utils.h"

bool	convert_percent(t_pinfo *info)
{
	int		padding;
	char	pad_char;

	padding = 1;
	pad_char = get_pad_char(info);
	if (!(info->flags & F_LEFTALIGN))
		add_padding(info, &padding, pad_char);
	info->ft_putc('%');
	info->count++;
	if (info->flags & F_LEFTALIGN)
		add_padding(info, &padding, pad_char);
	return (true);
}

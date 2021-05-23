/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_ptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleblanc <mleblanc@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 23:57:12 by mleblanc          #+#    #+#             */
/*   Updated: 2021/05/22 17:55:12 by mleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "convert_ptr.h"
#include "libft.h"
#include "utils.h"
#include "flags.h"
#include <stdlib.h>

bool	convert_ptr(t_pinfo *info)
{
	void	*ptr;
	char	*str;
	int		len;

	ptr = va_arg(info->va, void *);
	str = ft_ptoa_base(ptr, "0123456789abcdef");
	if (!str)
		return (false);
	len = (int)ft_strlen(str) + 2;
	if (!(info->flags & F_LEFTALIGN))
		add_padding(info, &len, ' ');
	ft_putstr("0x", info);
	ft_putstr(str, info);
	if (info->flags & F_LEFTALIGN)
		add_padding(info, &len, ' ');
	free(str);
	return (true);
}

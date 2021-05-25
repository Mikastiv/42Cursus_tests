/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleblanc <mleblanc@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 14:10:35 by mleblanc          #+#    #+#             */
/*   Updated: 2021/05/24 19:59:41 by mleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERT_H
# define CONVERT_H

# include "do_printf.h"
# include <stdbool.h>

typedef enum e_convert
{
	character,
	string,
	pointer,
	integer,
	u_integer,
	lower_hex,
	upper_hex,
	octal,
	percent,
}			t_convert;

bool	convert(const char **fmt, t_pinfo *info);

#endif

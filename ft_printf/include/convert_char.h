/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_char.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleblanc <mleblanc@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 14:27:04 by mleblanc          #+#    #+#             */
/*   Updated: 2021/05/23 17:02:02 by mleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERT_CHAR_H
# define CONVERT_CHAR_H

# include "do_printf.h"
# include <stdbool.h>
# include <wchar.h>

bool	convert_char(t_pinfo *info, wint_t c);

#endif

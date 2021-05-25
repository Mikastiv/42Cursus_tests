/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_uint.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleblanc <mleblanc@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 18:53:26 by mleblanc          #+#    #+#             */
/*   Updated: 2021/05/24 19:59:50 by mleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERT_UINT_H
# define CONVERT_UINT_H

# include "do_printf.h"
# include "convert.h"
# include <stdbool.h>

bool	convert_uint(t_pinfo *info, char *base, char *prefix, t_convert conv);

#endif
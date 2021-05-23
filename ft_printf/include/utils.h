/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleblanc <mleblanc@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 20:25:46 by mleblanc          #+#    #+#             */
/*   Updated: 2021/05/22 16:58:19 by mleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "do_printf.h"

void	add_padding(t_pinfo *info, int *len, char c);
void	ft_putstr(char *str, t_pinfo *info);
char	get_pad_char(t_pinfo *info);
int		to_int(const char **fmt);

#endif

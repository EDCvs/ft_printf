/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichimvis <ichimvis@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 14:19:15 by ichimvis          #+#    #+#             */
/*   Updated: 2026/11/16 15:34:07 by ichimvis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_str(char *s)
{
	if (!s)
		return (write(1, "(null)", 6));
	ft_putstr_fd(s, 1);
	return (ft_strlen(s));
}

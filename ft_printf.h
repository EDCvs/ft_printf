/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichimvis <ichimvis@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 14:13:39 by ichimvis          #+#    #+#             */
/*   Updated: 2026/11/16 15:30:34 by ichimvis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>
# include <unistd.h>

int	ft_printf(const char *str, ...);
int	print_char(char c);
int	print_str(char *s);
int	print_pointer(void *p);
int	print_int_dec(int x);
int	print_unsigned(unsigned int n);
int	print_hex_lower(unsigned int nbr);
int	print_hex_upper(unsigned int nbr);

#endif
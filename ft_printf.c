/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichimvis <ichimvis@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 11:45:27 by ichimvis          #+#    #+#             */
/*   Updated: 2026/11/16 15:50:40 by ichimvis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	type_help(char c, va_list *args)
{
	if (c == 'c')
		return (print_char(va_arg(*args, int)));
	if (c == 's')
		return (print_str(va_arg(*args, char *)));
	if (c == 'p')
		return (print_pointer(va_arg(*args, void *)));
	if (c == 'd' || c == 'i')
		return (print_int_dec(va_arg(*args, int)));
	if (c == 'u')
		return (print_unsigned(va_arg(*args, unsigned int)));
	if (c == 'x')
		return (print_hex_lower(va_arg(*args, unsigned int)));
	if (c == 'X')
		return (print_hex_upper(va_arg(*args, unsigned int)));
	if (c == '%')
		return (write(1, "%", 1));
	return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		count;

	i = 0;
	count = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%' && str[i + 1])
		{
			i++;
			count += type_help(str[i], &args);
		}
		else
			count += write(1, &str[i], 1);
		i++;
	}
	va_end(args);
	return (count);
}

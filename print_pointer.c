/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichimvis <ichimvis@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/11 11:27:18 by ichimvis          #+#    #+#             */
/*   Updated: 2026/11/16 15:14:59 by ichimvis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	put_ptr(unsigned long long nbr)
{
	char	*base;
	int		count;
	char	c;

	count = 0;
	base = "0123456789abcdef";
	if (nbr >= 16)
		count = +put_ptr(nbr / 16);
	c = base[nbr % 16];
	count += write(1, &c, 1);
	return (count);
}

int	print_pointer(void *p)
{
	unsigned long long	ptr;
	int					count;

	ptr = (unsigned long long)p;
	if (!ptr)
		return (write(1, "(nil)", 5));
	count = write(1, "0x", 2);
	count += put_ptr(ptr);
	return (count);
}

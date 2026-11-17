/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex_lower.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichimvis <ichimvis@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/16 10:07:53 by ichimvis          #+#    #+#             */
/*   Updated: 2026/11/16 15:54:36 by ichimvis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

static int	char_count(long int n)
{
	int	i;

	i = 0;
	if (n <= 0)
		i++;
	while (n != 0)
	{
		n = n / 16;
		i++;
	}
	return (i);
}

int	print_hex_lower(unsigned int nbr)
{
	char			c;
	char			*base;
	unsigned long	n;

	n = nbr;
	base = "0123456789abcdef";
	if (n >= 16)
		print_hex_lower(n / 16);
	c = base[n % 16];
	ft_putchar_fd(c, 1);
	return (char_count(nbr));
}

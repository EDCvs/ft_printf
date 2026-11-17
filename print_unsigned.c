/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichimvis <ichimvis@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/11 14:30:58 by ichimvis          #+#    #+#             */
/*   Updated: 2026/11/16 15:15:21 by ichimvis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	num_len(unsigned int num)
{
	unsigned long	len;
	unsigned long	n;

	n = (unsigned long)num;
	len = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

int	print_unsigned(unsigned int n)
{
	unsigned long	nb;

	nb = n;
	if (nb >= 10)
		print_unsigned(nb / 10);
	ft_putchar_fd((nb % 10) + '0', 1);
	return (num_len(n));
}

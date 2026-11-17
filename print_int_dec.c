/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int_dec.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichimvis <ichimvis@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/11 12:18:51 by ichimvis          #+#    #+#             */
/*   Updated: 2026/11/16 15:16:27 by ichimvis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

static int	get_digits(long n)
{
	int	len;

	len = 0;
	if (n < 0)
	{
		len++;
		n *= -1;
	}
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

int	print_int_dec(int x)
{
	ft_putnbr_fd(x, 1);
	return (get_digits(x));
}

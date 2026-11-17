/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_plain.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichimvis <ichimvis@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/09 13:26:37 by ichimvis          #+#    #+#             */
/*   Updated: 2026/11/10 11:45:48 by ichimvis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>

int ft_print_plain(const char *str)
{
    int i;

    i = 0;
    while (str[i] != '\0')
    {
        write(1, &str[i], 1);
        if ((write(1, &str[i], 1)) != 1)
            return -1;
        i++;
    }
    return i;
}

int main(void)
{
    char *str1 = "A\nB";
    ft_print_plain(str1);
    return 0;
}

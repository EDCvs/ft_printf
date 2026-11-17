/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichimvis <ichimvis@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/09 11:30:10 by ichimvis          #+#    #+#             */
/*   Updated: 2026/11/09 11:39:57 by ichimvis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>

void	ft_show(int marker, ...)
{
    va_list args;
    int num;
    char *str;
    int character;

    va_start(args, marker);
    num = va_arg(args, int);
    str = va_arg(args, char *);
    character = va_arg(args, int);
    
    printf("%d\n%s\n%c", num, str, character);
    va_end(args);
    
}

int main(void)
{
    ft_show(0, 12, "hello", 'c');
}

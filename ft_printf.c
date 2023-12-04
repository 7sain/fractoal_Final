/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hualhash <hualhash@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 19:56:59 by hualhash          #+#    #+#             */
/*   Updated: 2023/11/28 19:26:28 by hualhash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_printf(const char *format, ...)
{
	int			i;
	int			x;
	va_list		args;

	va_start(args, format);
	i = 0;
	x = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i++;
			x += checker(format[i], args);
			i++;
		}
		else
			x += write(1, &format[i++], 1);
	}
	va_end(args);
	return (x);
}

int	checker(char s, va_list args)
{
	int	x;

	x = 0;
	if (s == 'c')
		x += ft_putchar(va_arg(args, int));
	else if (s == 's')
		x += ft_putstr(va_arg(args, char *));
	else if (s == 'd' || s == 'i')
		x += ft_putnbr(va_arg(args, int));
	else if (s == 'u')
		x += ft_uputnbr(va_arg(args, int));
	else if (s == 'x' || s == 'X')
		x += ft_hex_base(va_arg(args, unsigned int), s);
	else if (s == 'p')
	{
		x += write(1, "0x", 2);
		x += ft_hex_base(va_arg(args, unsigned long), 'x');
	}
	else if (s == '%')
		x += ft_putchar('%');
	else if (s == '\n')
		write(1, "\n", 1);
	return (x);
}

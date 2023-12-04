/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hualhash <hualhash@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 23:11:02 by hualhash          #+#    #+#             */
/*   Updated: 2023/11/28 19:18:35 by hualhash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putnbr(int nb)
{
	int	i;

	i = 0;
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	if (nb < 0)
	{
		i += ft_putchar('-');
		nb *= -1;
	}
	if (nb >= 10)
	{
		i += ft_putnbr(nb / 10);
		i += ft_putnbr(nb % 10);
	}
	else
		i += ft_putchar(nb + '0');
	return (i);
}

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

int	ft_uputnbr(unsigned int nb)
{
	int	i;

	i = 0;
	if (nb < 0)
	{
		i += ft_putchar('-');
		nb *= -1;
	}
	if (nb >= 10)
	{
		i += ft_uputnbr(nb / 10);
		i += ft_uputnbr(nb % 10);
	}
	else
		i += ft_putchar(nb + '0');
	return (i);
}

int	ft_hex_base(unsigned long nb, int flag)
{
	int		c;
	char	*base;

	c = 0;
	if (nb == 0)
		return (write(1, "0", 1));
	if (flag == 'x')
		base = "0123456789abcdef";
	if (flag == 'X')
		base = "0123456789ABCDEF";
	if (nb >= 16)
	{
		c += ft_hex_base(nb / 16, flag);
		c += ft_hex_base(nb % 16, flag);
	}
	else
		c += ft_putchar(base[nb]);
	return (c);
}

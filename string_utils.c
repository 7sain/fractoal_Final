/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hualhash <hualhash@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 16:29:12 by hualhash          #+#    #+#             */
/*   Updated: 2023/11/30 18:54:41 by hualhash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_strncmp(char *s1, char *s2, int n)
{
	if (!s1 || !s2 || n <= 0)
		return (0);
	while (*s1 == *s2 && n > 0 && *s1 != '\0')
	{
		++s1;
		++s2;
		--n;
	}
	return (*s1 - *s2);
}

double	parse_fraction(const char **str, double pow)
{
	double	fractional_part;

	fractional_part = 0;
	while (**str)
	{
		pow /= 10;
		fractional_part += (**str - '0') * pow;
		++(*str);
	}
	return (fractional_part);
}

long	parse_integer(const char **str)
{
	long	integer_part;

	integer_part = 0;
	while (**str >= '0' && **str <= '9')
	{
		integer_part = (integer_part * 10) + (**str - '0');
		++(*str);
	}
	return (integer_part);
}

double	ft_atodbl(const char *str)
{
	long	integer_part;
	double	fractional_part;
	double	pow;
	int		sign;

	integer_part = 0;
	fractional_part = 0;
	pow = 1;
	sign = 1;
	while (*str == 32 || (*str >= 9 && *str <= 13))
		++str;
	if (*str == '-')
	{
		sign = -1;
		++str;
	}
	else if (*str == '+')
		++str;
	integer_part = parse_integer(&str);
	if (*str == '.')
	{
		++str;
		fractional_part = parse_fraction(&str, pow);
	}
	return ((integer_part + fractional_part) * sign);
}

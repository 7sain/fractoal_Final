/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hualhash <hualhash@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 16:29:06 by hualhash          #+#    #+#             */
/*   Updated: 2023/12/09 22:26:56 by hualhash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	map(double unscaled_num, double new_min, double new_max, double old_max)
{
	return ((new_max - new_min) * (unscaled_num / old_max) + new_min);
}

t_complex	sum_complex(t_complex z1, t_complex z2)
{
	t_complex	result;

	result.x = z1.x + z2.x;
	result.y = z1.y + z2.y;
	return (result);
}

t_complex	square_complex(t_complex z)
{
	t_complex	result;

	result.x = (z.x * z.x) - (z.y * z.y);
	result.y = 2 * z.x * z.y;
	return (result);
}

int	extension(char *s)
{
	int	has_dot;
	int	has_digits;

	has_dot = 0;
	has_digits = 0;
	while (*s)
	{
		if (*s == '.')
		{
			if (has_dot || !has_digits || (*(s + 1) == '\0' || *(s + 1) < '0'
					|| *(s + 1) > '9'))
				return (0);
			has_dot = 1;
		}
		else if (*s < '0' || *s > '9')
			return (0);
		else
			has_digits = 1;
		s++;
	}
	return (has_digits);
}

int	is_valid_number(char *s)
{
	if (!s || *s == '\0')
		return (0);
	if (*s == '+' || *s == '-')
	{
		s++;
		if (*s == '\0')
			return (0);
	}
	return (extension(s));
}

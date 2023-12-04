/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hualhash <hualhash@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 16:29:06 by hualhash          #+#    #+#             */
/*   Updated: 2023/12/04 20:08:09 by hualhash         ###   ########.fr       */
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

int	is_valid_number(char *s)
{
	if (!s || *s == '\0') // Check if the string is empty
		return (0);
	int hasDigits = 0; // Flag to check if there is at least one digit
	int hasDot = 0;    // Flag to check if there is at least one dot
	// Check the first character for '+' or '-'
	if (*s == '+' || *s == '-')
	{
		s++;
		// Exit if '+' or '-' is alone
		if (*s == '\0')
			return (0);
	}
	while (*s)
	{
		if (*s == '.')
		{
			// Exit if '.' is alone or there is no digit before or after it
			if (hasDot || !hasDigits || (*(s + 1) == '\0' || *(s + 1) < '0'
					|| *(s + 1) > '9'))
				return (0);
			hasDot = 1;
		}
		else if (*s < '0' || *s > '9') // Check if the character is not a digit
		{
			return (0);
		}
		else
		{
			hasDigits = 1;
		}
		s++;
	}
	return (hasDigits); // Return 1 if at least one digit is found, 0 otherwise
}

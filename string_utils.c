/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hualhash <hualhash@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 16:29:12 by hualhash          #+#    #+#             */
/*   Updated: 2023/12/04 18:41:15 by hualhash         ###   ########.fr       */
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

int is_valid_number(char *s, double min, double max)
{
    if (!s || *s == '\0') // Check if the string is empty
        return 0;

    int hasDigits = 0; // Flag to check if there is at least one digit
    int hasDot = 0;    // Flag to check if there is at least one dot

    // Check the first character for '+' or '-'
    if (*s == '+' || *s == '-')
    {
        s++;

        // Exit if '+' or '-' is alone
        if (*s == '\0')
            return 0;
    }

    double value = 0.0; // Variable to store the converted value

    while (*s)
    {
        if (*s == '.')
        {
            // Exit if '.' is alone or there is no digit before or after it
            if (hasDot || !hasDigits || (*(s + 1) == '\0' || *(s + 1) < '0' || *(s + 1) > '9'))
                return 0;

            hasDot = 1;
        }
        else if (*s < '0' || *s > '9') // Check if the character is not a digit
        {
            return 0;
        }
        else
        {
            hasDigits = 1;
            value = value * 10 + (*s - '0');
        }

        s++;
    }

    if (hasDot)
        value /= pow(10, s - strchr(s, '.') - 1); // Adjust value for fractional part

    return (hasDigits && value >= min && value <= max);
}
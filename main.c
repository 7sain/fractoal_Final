/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hualhash <hualhash@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 16:28:59 by hualhash          #+#    #+#             */
/*   Updated: 2023/12/04 18:37:06 by hualhash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	process_fractal(t_fractal *fractal)
{
	fractal_init(fractal);
	fractal_render(fractal);
	mlx_loop(fractal->mlx_connection);
}

// int	main(int ac, char **av)
// {
// 	t_fractal	fractal;

// 	if (ac != 2 && ac != 4)
// 	{
// 		ft_printf("Enter\n./fractol mandelbrot \n./fractol julia value1 value2\n");
// 		exit(1);
// 	}
// 	fractal.name = av[1];
// 	if (ft_strncmp(fractal.name, "mandelbrot", 10) == 0 && ac == 2)
// 	{
// 		process_fractal(&fractal);
// 	}
// 	else if (ac == 4 && ft_strncmp(fractal.name, "julia", 5) == 0)
// 	{
// 		fractal.julia_x = ft_atodbl(av[2]);
// 		fractal.julia_y = ft_atodbl(av[3]);
// 		process_fractal(&fractal);
// 	}
// 	else
// 	{
// 		ft_printf("Enter\n./fractol mandelbrot \n./fractol julia value1 value2\n");
// 		exit(1);
// 	}
// 	return (0);
// }

int main(int ac, char **av)
{
    t_fractal fractal;

    if (ac != 2 && ac != 4)
    {
        ft_printf("Enter\n./fractol mandelbrot \n./fractol julia value1 value2\n");
        exit(1);
    }
    fractal.name = av[1];
    if (ft_strncmp(fractal.name, "mandelbrot", 10) == 0 && ac == 2)
    {
        process_fractal(&fractal);
    }
    else if (ac != 4 || (ft_strncmp(av[1], "julia", 5) != 0) || 
        !is_valid_number(av[2], -2.0, 2.0) || !is_valid_number(av[3], -2.0, 2.0))
    {
        ft_printf("Enter\n./fractol julia value1 value2 (where value1 and value2 are in the range [-2.0, 2.0])\n");
        exit(1);
    }

        fractal.julia_x = ft_atodbl(av[2]);
        fractal.julia_y = ft_atodbl(av[3]);
        process_fractal(&fractal);
    
    // else
    // {
    //     ft_printf("Enter\n./fractol mandelbrot \n./fractol julia value1 value2\n");
    //     exit(1);
    // }
    return (0);
}

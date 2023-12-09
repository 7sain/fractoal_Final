/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hualhash <hualhash@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 16:28:59 by hualhash          #+#    #+#             */
/*   Updated: 2023/12/09 22:27:40 by hualhash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	process_fractal(t_fractal *fractal)
{
	fractal_init(fractal);
	fractal_render(fractal);
	mlx_loop(fractal->mlx_connection);
}

void	error_exit(void)
{
	ft_printf("Enter\n./fractol mandelbrot\n./fractol julia NUM1 NUM2\n");
	exit(1);
}

void	fractal_julia(t_fractal *fractal, char *av2, char *av3)
{
	if (!is_valid_number(av2) || !is_valid_number(av3))
		error_exit();
	fractal->julia_x = ft_atodbl(av2);
	fractal->julia_y = ft_atodbl(av3);
	process_fractal(fractal);
}

int	main(int ac, char **av)
{
	t_fractal	fractal;

	if (ac != 2 && ac != 4)
		error_exit();
	fractal.name = av[1];
	if (ft_strncmp(fractal.name, "mandelbrot", 10) == 0 && ac == 2)
		process_fractal(&fractal);
	else if (ac == 4 && ft_strncmp(fractal.name, "julia", 5) == 0)
		fractal_julia(&fractal, av[2], av[3]);
	else
		error_exit();
	return (0);
}

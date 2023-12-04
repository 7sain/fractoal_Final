/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hualhash <hualhash@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 16:28:51 by hualhash          #+#    #+#             */
/*   Updated: 2023/11/28 23:43:00 by hualhash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	close_handler(t_fractal *fractal)
{
	mlx_destroy_image(fractal->mlx_connection, fractal->img.img_ptr);
	mlx_destroy_window(fractal->mlx_connection, fractal->mlx_window);
	free(fractal->mlx_connection);
	exit(1);
}

int	key_handler(int keysym, t_fractal *fractal)
{
	if (keysym == 53)
		close_handler(fractal);
	if (keysym == 124)
		fractal->shift_x += (0.5 * fractal->zoom);
	else if (keysym == 123)
		fractal->shift_x -= (0.5 * fractal->zoom);
	else if (keysym == 125)
		fractal->shift_y -= (0.5 * fractal->zoom);
	else if (keysym == 126)
		fractal->shift_y += (0.5 * fractal->zoom);
	else if (keysym == 6)
		fractal->iterations_defintion += 10;
	else if (keysym == 7)
		fractal->iterations_defintion -= 10;
	fractal_render(fractal);
	return (0);
}

int	mouse_handler(int button, int x, int y, t_fractal *fractal)
{
	(void)x;
	(void)y;
	if (button == 5)
		fractal->zoom *= 0.95;
	else if (button == 4)
		fractal->zoom *= 1.05;
	fractal_render(fractal);
	return (0);
}

int	julia_track(int x, int y, t_fractal *fractal)
{
	if (!ft_strncmp(fractal->name, "julia", 5))
	{
		fractal->julia_x = (map(x, -2, +2, WIDTH) * fractal->zoom)
			+ fractal->shift_x;
		fractal->julia_y = (map(y, +2, -2, HEIGHT) * fractal->zoom)
			+ fractal->shift_y;
		fractal_render(fractal);
	}
	return (0);
}

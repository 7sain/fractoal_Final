/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hualhash <hualhash@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 16:28:37 by hualhash          #+#    #+#             */
/*   Updated: 2023/12/09 17:50:52 by hualhash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "minilibx/mlx.h"
# include <math.h>
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>

# define WIDTH 800
# define HEIGHT 800
# define BLACK 0x000000
# define WHITE 0xFFFFFF

typedef struct s_complex
{
	double	x;
	double	y;
}			t_complex;

typedef struct s_img
{
	void	*img_ptr;
	char	*pixels_ptr;
	int		bpp;
	int		endian;
	int		line_len;
}			t_img;

typedef struct s_fractal
{
	char	*name;
	void	*mlx_connection;
	void	*mlx_window;
	t_img	img;
	double	escape_value;
	int		iterations_defintion;
	double	shift_x;
	double	shift_y;
	double	zoom;
	double	julia_x;
	double	julia_y;
}			t_fractal;

int			ft_strncmp(char *s1, char *s2, int n);
void		fractal_init(t_fractal *fractal);
void		fractal_render(t_fractal *fractal);
t_complex	sum_complex(t_complex z1, t_complex z2);
t_complex	square_complex(t_complex z);
int			key_handler(int keysym, t_fractal *fractal);
int			close_handler(t_fractal *fractal);
int			mouse_handler(int button, int x, int y, t_fractal *fractal);
int			julia_track(int x, int y, t_fractal *fractal);
double		ft_atodbl(const char *str);
double		map(double unscaled_num, double new_min, double new_max,
				double old_max);

int			ft_printf(const char *format, ...);
int			ft_putchar(char c);
int			checker(char s, va_list args);
int			ft_putstr(char *str);
int			ft_putnbr(int nb);
int			ft_uputnbr(unsigned int nb);
int			ft_hex_base(unsigned long nb, int flag);
void		process_fractal(t_fractal *fractal);
int			is_valid_number(char *s);
char		*ft_strchr(const char *s, int c);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmckinle <gmckinle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 17:54:30 by gmckinle          #+#    #+#             */
/*   Updated: 2021/12/06 17:12:22 by gmckinle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define WIDTH 900
# define HEIGHT 900

# include "mlx/mlx.h"
# include "libft/libft.h"

# include <math.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>


typedef struct	s_image {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_image;

typedef	struct		s_color
{
	int8_t			channel[4];
}					t_color;

typedef struct	s_complex {
	double	im;
	double	re;
}				t_complex;

typedef struct	s_fractal {
	void		*mlx;
	void		*win;
	t_image		image;
	char		*name;
	int			iter;
	int			max_iter;
	int			x;
	int			y;
	int			color_type;
	double		zoom;
	double		x_step;
	double		y_step;
	t_complex	c;
	t_complex	z;
	t_complex	k;
	t_complex	min;
	t_complex	max;
	t_complex	factor;
	
}				t_fractal;

/* Init */
t_image		*image_init(void *mlx);
t_complex	complex_init(double re, double im);
t_fractal	*fractal_init(char *argv);

/* utils */
void	error(char *str);
void	my_mlx_pixel_put(t_image *image, int x, int y, int color);

void	colors(t_fractal *f);

int		key_press(int keycode, t_fractal *f);

void    help();
void    help_win(t_fractal *f);

/* fractals */
void	mandelbrot(t_fractal *f);
void	julia(t_fractal *f);

#endif

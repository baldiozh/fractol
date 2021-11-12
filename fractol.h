/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmckinle <gmckinle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 17:54:30 by gmckinle          #+#    #+#             */
/*   Updated: 2021/11/12 18:49:59 by gmckinle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define WIDTH 800
# define HEIGHT 800

# include "mlx/mlx.h"

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

typedef struct	s_complex {
	double	im;
	double	re;
}				t_complex;

typedef struct	s_fractal {
	void		*mlx;
	void		*win;
	t_image		image;
	char		*name;
	int			max_iter;
	int			x;
	int			y;
	t_complex	factor;
	t_complex	c;
	t_complex	z;
	t_complex	min;
	t_complex	max;
	
}				t_fractal;

/* Init */
t_image		*ImageInit(void *mlx);
t_complex	ComplexInit(double re, double im);
t_fractal	*FractalInit(char *argv);

/* libft */
void	ft_putstr(char *s);
int		ft_strncmp(const char *str1, const char *str2, size_t n);

/* utils */
void	Error(char *str);
void	my_mlx_pixel_put(t_image *image, int x, int y, int color);

/* fractals */
void	mandelbrot(t_fractal *f);

#endif

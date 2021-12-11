/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmckinle <gmckinle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 17:54:30 by gmckinle          #+#    #+#             */
/*   Updated: 2021/12/10 22:24:16 by gmckinle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define WIDTH 720
# define HEIGHT 720

# define EXIT 53
# define PLUS 24
# define MINUS 27
# define UP 126
# define DOWN 125
# define LEFT 123
# define RIGHT 124
# define C 8
# define R 15
# define M 46

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
	int			move;

	
}				t_fractal;

/* Init */
t_image		*image_init(void *mlx);
t_complex	complex_init(double re, double im);
t_fractal	*fractal_init(char *argv);

/* utils */

void	error(char *str);
void	start_fractal(t_fractal *f);

void	colors(t_fractal *f);

int		key_press(int keycode, t_fractal *f);
void	recount(t_fractal *f, int x, int y);
int		mouse_press(int button, int x, int y, t_fractal *f);
int		mouse_move(int x, int y, t_fractal *f);
int		red_cross(void);

void    help();
void    help_win(t_fractal *f);


/* fractals */
void	mandelbrot(t_fractal *f);
void	julia(t_fractal *f);

#endif

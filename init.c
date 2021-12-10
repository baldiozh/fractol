/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmckinle <gmckinle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 18:43:28 by gmckinle          #+#    #+#             */
/*   Updated: 2021/12/10 20:56:49 by gmckinle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_image		*image_init(void *mlx)
{
	t_image	*image;
	
	image = (t_image *)malloc(sizeof(t_image));
	if (!image)
		error("\x1b[31mImage's memory allocation error.\n");
	image->img = mlx_new_image(mlx, WIDTH, HEIGHT);
	if (image->img == NULL)
		error("\x1b[31mImage create error.\n");
	image->addr = mlx_get_data_addr(image->img, &image->bits_per_pixel, &image->line_length, &image->endian);
	return (image);
}

t_complex	complex_init(double re, double im)
{
    t_complex complex;
    
    complex.re = re;
    complex.im = im;
    return (complex);
}

t_fractal	*fractal_init(char *argv)
{
	t_fractal *f;

	f = (t_fractal *)malloc(sizeof(t_fractal));
	if (!f)
		error("\x1b[31mFractals's memory allocation error.\n");
	f->mlx = mlx_init();
	f->win = mlx_new_window(f->mlx, WIDTH, HEIGHT, argv);
	f->image = *image_init(f->mlx);
	f->name = argv;
	f->iter = 0;
	f->max_iter = 100;
	f->x = 0;
	f->y = 0;
	f->move = 0;
	f->color_type = 0;
	f->zoom = 1.0;
	f->k = complex_init(-0.4, 0.6);
	f->min = complex_init(-2.0, -2.0);
	f->max.re = 2.0;
	f->max.im = f->min.im + (f->max.re - f->min.re) * (HEIGHT / WIDTH);
	f->x_step = (f->max.re - f->min.re) / WIDTH;
	f->y_step = (f->max.im - f->min.im) / HEIGHT;
	return (f);
}
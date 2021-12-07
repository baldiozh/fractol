/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmckinle <gmckinle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 18:43:28 by gmckinle          #+#    #+#             */
/*   Updated: 2021/12/07 18:59:52 by gmckinle         ###   ########.fr       */
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

// t_color	get_color(t_fractal *f)
// {
// 	int	color;
// 	double	t;

// 	t = (double)f->iter / f->max_iter;
// 	color.channel[0] = 0;
// 	color.channel[(0 + f->color_type) % 3 + 1] =
// 		(int8_t)(9 * (1 - t) * pow(t, 3) * 255);
// 	color.channel[(1 + f->color_type) % 3 + 1] =
// 		(int8_t)(15 * pow((1 - t), 2) * pow(t, 2) * 255);
// 	color.channel[(2 + f->color_type) % 3 + 1] =
// 		(int8_t)(8.5 * pow((1 - t), 3) * t * 255);
// 	return (color);
// }

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
	f->color_type = 2;
	f->zoom = 1.0;
	f->x_step = 0;
	f->y_step = 0;
	f->k = complex_init(-0.4, 0.6);
	f->min = complex_init(-2.0, -2.0);
	f->max.re = 2.0;
	f->max.im = f->min.im + (f->max.re - f->min.re) * (HEIGHT / WIDTH);
	f->factor = complex_init((f->max.re - f->min.re) / (WIDTH - 1),
		(f->max.im - f->min.im) / (HEIGHT - 1));
	return (f);
}
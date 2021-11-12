/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmckinle <gmckinle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 18:43:28 by gmckinle          #+#    #+#             */
/*   Updated: 2021/11/12 16:59:25 by gmckinle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_image		*ImageInit(void *mlx)
{
	t_image	*image;
	
	image = (t_image *)malloc(sizeof(t_image));
	if (!image)
		Error("\x1b[31mImage's memory allocation error.\n");
	image->img = mlx_new_image(mlx, WIGHT, HEIGHT);
	image->addr = mlx_get_data_addr(image->img, &image->bits_per_pixel, &image->line_length, &image->endian);
	return (image);
}


t_complex	ComplexInit(double re, double im)
{
    t_complex complex;
    
    complex.re = re;
    complex.im = im;
    return (complex);
}

t_fractal	*FractalInit(char *argv)
{
	t_fractal *f;

	f = (t_fractal *)malloc(sizeof(t_fractal));
	if (!f)
		Error("\x1b[31mFractals's memory allocation error.\n");
	f->mlx = mlx_init();
	f->win = mlx_new_window(f->mlx, WIGHT, HEIGHT, argv);
	f->image = *ImageInit(f->mlx);
	f->name = argv;
	f->max_iter = 50;
	f->x = 0;
	f->y = 0;
	//C Z
	// f->min = ComplexInit(-2.0, -2.0);
	// f->max.re = 2.0;
	// max.im = min.im + (max.re - min.re) * (HEIGHT / WIDTH);
	return (f);
}
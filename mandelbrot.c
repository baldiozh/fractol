/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmckinle <gmckinle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 17:26:51 by gmckinle          #+#    #+#             */
/*   Updated: 2021/11/12 19:07:59 by gmckinle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	testmoves(t_fractal *f)
{
	/* white window */
	while(f->y < HEIGHT)
	{
		f->x = 0;
		while(f->x < WIDTH)
		{
			my_mlx_pixel_put(&f->image, f->x, f->y, 0X00FFF0F0);
			f->x++;
		}
		f->y++;
	}
	f->x = 0;
	f->y = 0;
	/* coordinate plane */
	while (f->x < 800 && f->y < 800)
	{
		my_mlx_pixel_put(&f->image, f->x, 400, 0X000F0FFF);
		my_mlx_pixel_put(&f->image, 400, f->y, 0X000F0FFF);
		f->x++;
		f->y++;
	}
}

void	mandelbrot(t_fractal *f)
{
	int		iter;
	
	f->factor.re = (f->max.re - f->min.re) / (WIDTH - 1);
	f->factor.im = (f->max.im - f->min.im) / (HEIGHT - 1);
	while (f->y < HEIGHT)
	{
		f->c.im = f->max.im - f->y * f->factor.im;
		f->x = 0;
		while (f->x < WIDTH)
		{
			f->c.re = f->min.re + f->x * f->factor.re;
			f->z = ComplexInit(f->c.re, f->c.im);
			// printf("%f\n", f->c.re);
			iter = 0;
			while (pow(f->z.re, 2.0) + pow(f->z.im, 2.0) <= 4 && iter < f->max_iter)
			{
				f->z = ComplexInit(
					pow(f->z.re, 2.0) - pow(f->z.im, 2.0) + f->c.re,
					2.0 * f->z.re * f->z.im + f->c.im);
				iter++;
			}
			// Установка цвета точки
			if (pow(f->z.re, 2.0) + pow(f->z.im, 2.0) > 4)
				my_mlx_pixel_put(&f->image, f->x, f->y, 0X00FFF0F0);
			f->x++;
		}
		f->y++;
	}
	
	mlx_put_image_to_window(f->mlx, f->win, f->image.img, 0, 0);
}
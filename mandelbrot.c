/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmckinle <gmckinle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 17:26:51 by gmckinle          #+#    #+#             */
/*   Updated: 2021/12/05 18:33:20 by gmckinle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	mandelbrot(t_fractal *f)
{	
	
	f->factor.re = (f->max.re - f->min.re) / (WIDTH - 1);
	f->factor.im = (f->max.im - f->min.im) / (HEIGHT - 1);
	while (f->y < HEIGHT)
	{
		f->c.im = f->max.im - f->y * f->factor.im;
		f->x = 0;
		while (f->x < WIDTH)
		{
			f->c.re = f->min.re + f->x * f->factor.re;
			f->z = complex_init(f->c.re, f->c.im);
			f->iter = 0;
			//Проверяем принадлежность точки (будет ли выходить за пределы 5ти)
			while (pow(f->z.re, 2.0) + pow(f->z.im, 2.0) <= 4 && f->iter < f->max_iter)
			{
				f->z = complex_init(
					pow(f->z.re, 2.0) - pow(f->z.im, 2.0) + f->c.re,
					2.0 * f->z.re * f->z.im + f->c.im);
				f->iter++;
			}
			// Установка цвета точки, если точка не входит в множество
			if (pow(f->z.re, 2.0) + pow(f->z.im, 2.0) > 4)
				colors(f);
			f->x++;
		}
		f->y++;
	}
	mlx_put_image_to_window(f->mlx, f->win, f->image.img, 0, 0);
}
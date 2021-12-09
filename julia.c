/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmckinle <gmckinle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 19:43:58 by gmckinle          #+#    #+#             */
/*   Updated: 2021/12/09 20:04:53 by gmckinle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	julia(t_fractal *f) //z - пиксели, а с - положение мышки
{
	//добавить значения для положении мыши для статичной джулии и управление мышью
	mlx_clear_window(f->mlx, f->win);
	f->y = 0;
	while (f->y++ < HEIGHT)
	{
		f->x = 0;
		while (f->x++ < WIDTH)
		{
			f->iter = 0;
			f->z.re = f->min.re + f->x_step * f->x;
			f->z.im = f->max.im - f->y_step * f->y;
			while (f->iter++ < f->max_iter && (pow(f->z.re, 2.0)
				+ pow(f->z.im, 2.0) <= 4))
			{
				f->z = complex_init(
					pow(f->z.re, 2.0) - pow(f->z.im, 2.0) + f->k.re, 
					2 * f->z.re * f->z.im + f->k.im);
			}
			if (pow(f->z.re, 2.0) + pow(f->z.im, 2.0) > 4)
				colors(f);				
		}
	}
	mlx_put_image_to_window(f->mlx, f->win, f->image.img, 0, 0);
}

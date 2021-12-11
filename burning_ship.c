/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmckinle <gmckinle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 21:05:29 by gmckinle          #+#    #+#             */
/*   Updated: 2021/12/11 21:06:09 by gmckinle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	burning_ship(t_fractal *f)
{
	mlx_clear_window(f->mlx, f->win);
	f->y = 0;
	while (f->y++ < HEIGHT)
	{
		f->c.im = f->max.im - f->y * f->y_step;
		f->x = 0;
		while (f->x++ < WIDTH)
		{
			f->iter = 0;
			f->c.re = f->min.re + f->x * f->x_step;
			f->z = complex_init(f->c.re, f->c.im);
			while (pow(f->z.re, 2.0) + pow(f->z.im, 2.0) <= 4.0
				&& f->iter < f->max_iter)
			{
				f->z = complex_init(
						pow(f->z.re, 2.0) - pow(f->z.im, 2.0) + f->c.re,
						-2.0 * fabs(f->z.re * f->z.im) + f->c.im);
				f->iter++;
			}
			if (pow(f->z.re, 2.0) + pow(f->z.im, 2.0) > 4.0)
				colors(f);
		}
	}
	mlx_put_image_to_window(f->mlx, f->win, f->image.img, 0, 0);
}

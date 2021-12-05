/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmckinle <gmckinle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 19:43:58 by gmckinle          #+#    #+#             */
/*   Updated: 2021/12/05 19:38:49 by gmckinle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	julia(t_fractal *f)
{
	double	swap;

	f->y = 0;
	while (f->y++ < HEIGHT)
	{
		f->x = 0;
		while (f->x++ < WIDTH)
		{
			f->iter = 0;
			f->z.re = (f->x - WIDTH / 2) / (0.25 * WIDTH );
			f->z.im = (f->y - HEIGHT / 2) / (0.25 * HEIGHT);
			while (f->iter++ < f->max_iter && (pow(f->z.re, 2.0)
					+ pow(f->z.im, 2.0) <= 4))
			{
				swap = pow(f->z.re, 2.0) - pow(f->z.im, 2.0) + f->k.re;
				f->z.im = 2 * f->z.re * f->z.im + f->k.im;
				f->z.re = swap;
			}
			if (pow(f->z.re, 2.0) + pow(f->z.im, 2.0) > 4)
				colors(f);
		}
	}
	mlx_put_image_to_window(f->mlx, f->win, f->image.img, 0, 0);
}


// while(f->y < HEIGHT)
// 	{
// 		f->x = 0;
// 		while(f->x < WIDTH)
// 		{
// 			f->iter = 0;
// 			f->z = complex_init(f->c.re, f->c.im);
// 			//Проверяем принадлежность точки (будет ли выходить за пределы 5ти)
// 			while (pow(f->z.re, 2.0) + pow(f->z.im, 2.0) <= 4 && f->iter < f->max_iter)
// 			{
// 				f->z = complex_init(
// 					pow(f->z.re, 2.0) - pow(f->z.im, 2.0) + f->k.re,
// 					2.0 * f->z.re * f->z.im + f->k.im);
// 				f->iter++;
// 			}
// 			// Установка цвета точки, если точка не входит в множ-во
// 			if (pow(f->z.re, 2.0) + pow(f->z.im, 2.0) > 4)
// 				my_mlx_pixel_put(&f->image, f->x, f->y, 0xfa8072);
// 				// colors(f);
// 			f->x++;
// 		}
// 		f->y++;
// 	}

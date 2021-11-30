/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmckinle <gmckinle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 19:43:58 by gmckinle          #+#    #+#             */
/*   Updated: 2021/11/30 19:02:03 by gmckinle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	julia(t_fractal *f)
{
	while(f->y < HEIGHT)
	{
		f->x = 0;
		while(f->x < WIDTH)
		{
			f->z = complex_init(f->c.re, f->c.im);
			//Проверяем принадлежность точки (будет ли выходить за пределы 5ти)
			while (pow(f->z.re, 2.0) + pow(f->z.im, 2.0) < 5 && f->iter < f->max_iter)
			{
				f->z = complex_init(
					pow(f->z.re, 2.0) - pow(f->z.im, 2.0) + f->k.re,
					2.0 * f->z.re * f->z.im + f->k.im);
				f->iter++;
			}
			// Установка цвета точки, если точка не входит в множ-во
			if (pow(f->z.re, 2.0) + pow(f->z.im, 2.0) > 4)
				my_mlx_pixel_put(&f->image, f->x, f->y, 0xfa8072);
			f->x++;
		}
		f->y++;
	}

	mlx_put_image_to_window(f->mlx, f->win, f->image.img, 0, 0);
}





// f->k = complex_init(
	// 	4 * ((double)f->x / WIDTH - 0.5),
	// 	4 * ((double)(HEIGHT - f->y) / HEIGHT - 0.5));
	
// while (pow(f->z.re, 2.0) + pow(f->z.im, 2.0) < 5
	// 	&& f->iter < f->max_iter)
	// {
	// 	f->z = complex_init(
	// 		pow(f->z.re, 2.0) - pow(f->z.im, 2.0) + f->k.re,
	// 		2.0 * f->z.re * f->z.im + f->k.im);
	// 	f->iter++;
	// }
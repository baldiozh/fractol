/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmckinle <gmckinle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 17:26:51 by gmckinle          #+#    #+#             */
/*   Updated: 2021/11/12 17:23:33 by gmckinle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	mandelbrot(t_fractal *f)
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
	
	mlx_put_image_to_window(f->mlx, f->win, f->image.img, 0, 0);
}
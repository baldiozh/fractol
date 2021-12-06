/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmckinle <gmckinle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 14:39:41 by gmckinle          #+#    #+#             */
/*   Updated: 2021/12/06 18:48:28 by gmckinle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_mlx_pixel_put(t_image *image, int x, int y, int color)
{
	char	*dst;

	dst = image->addr + (y * image->line_length + x * (image->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	colors(t_fractal *f)
{
	int color; 
	
	double t = f->iter / f->max_iter;
	if (f->iter < 20)
	{
		t += (1 - t) * 1;
		color = (t / ((f->color_type + 1) % 3 + 1) * 255);
		my_mlx_pixel_put(&f->image, f->x, f->y, color);
	}
	else if (f->iter > 20 && f->iter < 40)
	{
		t += (1 - t) * 10;
		color = (t / ((f->color_type + 1) % 3 + 1) * 255);
		my_mlx_pixel_put(&f->image, f->x, f->y, color);
	}
	else if (f->iter > 40 && f->iter < 100)
	{
		t += (1 - t) * 1000;
		color = (t / ((f->color_type + 1) % 3 + 1) * 255);
		my_mlx_pixel_put(&f->image, f->x, f->y, color);
	}
}

// t = (double)iteration / (double)max_iteration;

// red = (int)(9 * (1 - t) * pow(t, 3) * 255);
// green = (int)(15 * pow((1 - t), 2) * pow(t, 2) * 255);
// blue = (int)(8.5 * pow((1 - t), 3) * t * 255);

	
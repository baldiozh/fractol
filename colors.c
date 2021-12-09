/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmckinle <gmckinle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 14:39:41 by gmckinle          #+#    #+#             */
/*   Updated: 2021/12/09 16:59:14 by gmckinle         ###   ########.fr       */
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
	double	t;
	int		pixel; 
	
	t = (double)f->iter / f->max_iter;
	pixel = (f->y * f->image.line_length + 4 * f->x);
	// printf("%d\n", f->image.line_length);
	// printf("%d\n", pixel);
	if (f->color_type == 0) /* blue, sky */
	{
		f->image.addr[pixel] = (int)(20 * pow((1 - t), 2) * pow(t, 2) * 255);
		f->image.addr[pixel + 1] = (int)(20 * pow((1 - t), 2) * pow(t, 2) * 255);
	}
	else if (f->color_type == 1) /* green, yellow */
	{
		f->image.addr[pixel + 1] = (int)(20 * pow((1 - t), 2) * pow(t, 2) * 255);
		f->image.addr[pixel + 2] = (int)(20 * pow((1 - t), 2) * pow(t, 2) * 255);
	}
	else if (f->color_type == 2) /* red, purple */
	{
		f->image.addr[pixel + 2] = (int)(20 * pow((1 - t), 2) * pow(t, 2) * 255);
		f->image.addr[pixel] = (int)(20 * pow((1 - t), 2) * pow(t, 2) * 255);
	}
	
}

// red = (int)(9 * (1 - t) * pow(t, 3) * 255);
// green = (int)(15 * pow((1 - t), 2) * pow(t, 2) * 255);
// blue = (int)(8.5 * pow((1 - t), 3) * t * 255);

	
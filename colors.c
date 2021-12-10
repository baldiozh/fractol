/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmckinle <gmckinle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 14:39:41 by gmckinle          #+#    #+#             */
/*   Updated: 2021/12/10 21:14:50 by gmckinle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	colors(t_fractal *f)
{
	double	t;
	int		pixel; 
	
	t = (double)f->iter / f->max_iter;
	pixel = f->y * f->image.line_length + 4 * f->x;
	// printf("%d-", pixel);
	// printf("%d\n", f->image.line_length);
	// write(1, "jfghdi", 6);
	// if (pixel > 2000000)
	// 	pixel = 0;	
	if (f->color_type == 0) /* blue, sky */
	{
		f->image.addr[pixel + 0] = (int)(20 * pow((1 - t), 2) * pow(t, 2) * 255);
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

	
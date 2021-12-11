/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmckinle <gmckinle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 14:39:41 by gmckinle          #+#    #+#             */
/*   Updated: 2021/12/11 21:16:03 by gmckinle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	colors(t_fractal *f)
{
	double	t;
	int		pixel;

	t = (double)f->iter / f->max_iter;
	pixel = f->y * f->image.line_length + 4 * f->x;
	if (f->color_type == 0)
	{
		f->image.addr[pixel + 0]
			= (int)(20 * pow((1 - t), 2) * pow(t, 2) * 255);
		f->image.addr[pixel + 1]
			= (int)(20 * pow((1 - t), 2) * pow(t, 2) * 255);
	}
	else if (f->color_type == 1)
		f->image.addr[pixel + 1]
			= (int)(20 * pow((1 - t), 2) * pow(t, 2) * 255);
	else if (f->color_type == 2)
	{
		f->image.addr[pixel + 2]
			= (int)(20 * pow((1 - t), 2) * pow(t, 2) * 255);
		f->image.addr[pixel]
			 = (int)(20 * pow((1 - t), 2) * pow(t, 2) * 255);
	}
}

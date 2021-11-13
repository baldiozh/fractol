/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmckinle <gmckinle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 14:39:41 by gmckinle          #+#    #+#             */
/*   Updated: 2021/11/13 19:29:22 by gmckinle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	colors(t_fractal *f)
{
	double	pixel;
	int		i;

	i = 4;
	double k = 0;
	pixel = pow(f->z.re, 2.0) + pow(f->z.im, 2.0);
	while(k < 1)
	{
		if (pixel > i && pixel < i+1)
			my_mlx_pixel_put(&f->image, f->x, f->y, f->color);
		i++;
		k += 0.1;
		f->color = (255 - (0.9 * 255)) / k;;
	}
	
	
	//десятеричная система 277335787
	// if (pixel > 5 && pixel < 6)
	// 	my_mlx_pixel_put(&f->image, f->x, f->y, 0x1087ceeb); //16теричная 25677547


}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmckinle <gmckinle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 18:43:28 by gmckinle          #+#    #+#             */
/*   Updated: 2021/11/12 16:22:44 by gmckinle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_image		*ImageInit(void *mlx)
{
	t_image	*image;
	
	image = (t_image *)malloc * (sizeof(t_image));
	if (!img)
		Error("\x1b[31mImage's memory allocation error.\n");
	image->img = mlx_new_image(mlx, WIGHT, HEIGHT);
	image->addr = mlx_get_data_addr(image->img, image->bits_per_pixel, image->line_length, image->endian);
	return (image);
}

t_fractal	*FractalInit(char *argv)
{
	void	*mlx;

	f = (t_fractal *)malloc * (sizeof(t_fractal));
	if (!f)
		Error("\x1b[31mFractals's memory allocation error.\n");
	f->mlx = mlx_init();
	f->win = mlx_new_window(f->mlx, WIGHT, HEIGHT, argv);
	f->name = argv;
	max_iter = 50;
	return (f);
}
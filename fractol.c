/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmckinle <gmckinle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 18:23:44 by gmckinle          #+#    #+#             */
/*   Updated: 2021/10/07 15:30:37 by gmckinle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_mlx_pixel_put(t_image *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	main(void)
{
	t_fractal fractal;
	
	fractal.mlx = mlx_init();
	fractal.win = mlx_new_window(fractal.mlx, 800, 800, "fract-ol");
	fractal.img.img = mlx_new_image(fractal.mlx, 800, 800);
	fractal.img.addr = mlx_get_data_addr(fractal.img.img, &fractal.img.bits_per_pixel, &fractal.img.line_length, &fractal.img.endian);
	
	for(int i = 0; i < 800; i++)
	{
		my_mlx_pixel_put(&fractal.img, i, i, 0X00FFFFFF);
	}
	mlx_put_image_to_window(fractal.mlx, fractal.win, fractal.img.img, 0, 0);
	
	mlx_loop(fractal.mlx);
	return (0);
}
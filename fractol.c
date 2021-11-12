/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmckinle <gmckinle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 18:23:44 by gmckinle          #+#    #+#             */
/*   Updated: 2021/11/12 17:00:00 by gmckinle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// void	NameOfFractal(t_fractal *f) 
// {
// 	if (ft_strncmp(f->name, "mandelbrot", 10) == 0)
// 		mandelbrot();
// 	else if(ft_strncmp(f->name, "julia", 5) == 0)
// 		julia();
// }

int	main(int argc, char **argv)
{
	t_fractal *f;

	
	if (argc != 2)
		Error("\x1b[1;31mEnter a name.\n");
	f = FractalInit(argv[1]);

	// int y = 0;
	// int x = 0;
	// /* white window */
	// while(y < HEIGHT)
	// {
	// 	x = 0;
	// 	while(x < WIGHT)
	// 	{
	// 		my_mlx_pixel_put(&fractal.img, x, y, 0X00FFF0F0);
	// 		x++;
	// 	}
	// 	y++;
	// }
	// x = 0;
	// y = 0;
	// /* coordinate plane */
	// while (x < 800 && y < 800)
	// {
	// 	my_mlx_pixel_put(&fractal.img, x, 400, 0X000F0FFF);
	// 	my_mlx_pixel_put(&fractal.img, 400, y, 0X000F0FFF);
	// 	x++;
	// 	y++;
	// }
	
	mlx_loop(f->mlx);
	return (0);
}
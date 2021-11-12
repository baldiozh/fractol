/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmckinle <gmckinle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 18:23:44 by gmckinle          #+#    #+#             */
/*   Updated: 2021/11/12 16:21:47 by gmckinle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	Error(char *str)
{
	ft_putstr(str);
	exit (EXIT_FAILURE);
}

void	my_mlx_pixel_put(t_image *image, int x, int y, int color)
{
	char	*dst;

	dst = image->addr + (y * image->line_length + x * (image->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

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
	f->image = ImageInit(f->mlx);
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
	
	// mlx_put_image_to_window(f->mlx, f->win, f->img->img, 0, 0);
	mlx_loop(f->mlx);
	return (0);
}
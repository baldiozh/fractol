/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmckinle <gmckinle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 18:23:44 by gmckinle          #+#    #+#             */
/*   Updated: 2021/12/11 17:38:52 by gmckinle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	start_fractal(t_fractal *f) 
{
	if (ft_strncmp(f->name, "mandelbrot\0", 11) == 0)
		mandelbrot(f);
	else if (ft_strncmp(f->name, "julia\0", 6) == 0)
		julia(f);
	else
		error("\x1b[31mEnter fractal's name:\n-mandelbrot;\n-julia.\n");
}

int	main(int argc, char **argv)
{
	t_fractal *f;

	if (argc > 4 || argc < 2)
		error("\x1b[31mEnter fractal's name:\n-mandelbrot;\n-julia.\n");
	f = fractal_init(argv[1]);
	if (argc == 2)
		f->k = complex_init(-0.1, 0.9);
	else if (argc == 4) /* julia only */
	{
		f->stat = 1;
		f->x = ft_atoi(argv[2]);
		f->y = ft_atoi(argv[3]);
		f->k = complex_init(
			(f->x - WIDTH / 2) / (0.25 * WIDTH) + f->x_step,
			(f->y - HEIGHT / 2) / (0.25 * HEIGHT) + f->y_step);
	}
	start_fractal(f);
	mlx_hook(f->win, 6, 0, mouse_move, f);
	mlx_mouse_hook(f->win, mouse_press, f);
	mlx_hook(f->win, 2, 0, key_press, f);
	mlx_hook(f->win, 17, 0, red_cross, f);
	help();
	mlx_loop(f->mlx);	
	return (0);
}
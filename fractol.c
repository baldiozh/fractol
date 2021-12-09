/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmckinle <gmckinle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 18:23:44 by gmckinle          #+#    #+#             */
/*   Updated: 2021/12/09 16:39:54 by gmckinle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	name_fractal(t_fractal *f) 
{
	if (ft_strncmp(f->name, "mandelbrot", 10) == 0)
		mandelbrot(f);
	else if(ft_strncmp(f->name, "julia", 5) == 0)
		julia(f); //mlx_hook(f->win, 6, 0, mouse_move, f);
	else
		error("\x1b[31mFractals's name error.\n");
}

int	main(int argc, char **argv)
{
	t_fractal *f;

	if (argc > 4 || argc == 1)
		error("\x1b[1;31mEnter a name.\n");
	if (argc == 4) /* julia only */
	{
		f = fractal_init(argv[1]);
		name_fractal(f);
		f->x = ft_atoi(argv[2]);
		f->y = ft_atoi(argv[3]);
		ft_putnbr_fd(f->x, 1);
	}
	else
	{
		f = fractal_init(argv[1]);
		name_fractal(f);
	}
	mlx_hook(f->win, 2, 0, key_press, f);
	mlx_hook(f->win, 4, 0, mouse_press, f);
	help();
	mlx_string_put(f->mlx, f->win, 840, 895, 0xfffafa, "H - Help");
	mlx_loop(f->mlx);	
	return (0);
}
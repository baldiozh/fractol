/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmckinle <gmckinle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 18:23:44 by gmckinle          #+#    #+#             */
/*   Updated: 2021/11/30 16:41:34 by gmckinle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	name_fractal(t_fractal *f) 
{
	if (ft_strncmp(f->name, "mandelbrot", 10) == 0)
		mandelbrot(f);
	else if(ft_strncmp(f->name, "julia", 5) == 0)
		julia(f);
	else
		error("\x1b[31mFractals's name error.\n");
}

int	main(int argc, char **argv)
{
	t_fractal *f;

	
	if (argc != 2)
		error("\x1b[1;31mEnter a name.\n");
	f = fractal_init(argv[1]);
	name_fractal(f);
	mlx_hook(f->win, 2, 0, key_press, f);
	help();
	mlx_loop(f->mlx);	
	return (0);
}
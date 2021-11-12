/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmckinle <gmckinle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 18:23:44 by gmckinle          #+#    #+#             */
/*   Updated: 2021/11/12 17:03:45 by gmckinle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	NameOfFractal(t_fractal *f) 
{
	if (ft_strncmp(f->name, "mandelbrot", 10) == 0)
		mandelbrot(f);
	else
		Error("\x1b[31mFractals's name error.\n");
	// else if(ft_strncmp(f->name, "julia", 5) == 0)
	// 	julia();
}

int	main(int argc, char **argv)
{
	t_fractal *f;

	
	if (argc != 2)
		Error("\x1b[1;31mEnter a name.\n");
	f = FractalInit(argv[1]);
	NameOfFractal(f);
	
	mlx_loop(f->mlx);
	return (0);
}
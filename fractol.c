/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmckinle <gmckinle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 18:23:44 by gmckinle          #+#    #+#             */
/*   Updated: 2021/12/10 18:37:37 by gmckinle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	start_fractal(t_fractal *f) 
{
	if (ft_strncmp(f->name, "mandelbrot", ft_strlen(f->name)) == 0)
			mandelbrot(f);
	else if(ft_strncmp(f->name, "julia", ft_strlen(f->name)) == 0)
		julia(f);
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
		start_fractal(f);
		// f->x = ft_atoi(argv[2]);
		// f->y = ft_atoi(argv[3]);
		// ft_putnbr_fd(f->x, 1);
	}
	else
	{
		f = fractal_init(argv[1]);
		start_fractal(f);
	}
	mlx_hook(f->win, 2, 0, key_press, f);
	mlx_mouse_hook(f->win, mouse_press, f);
	mlx_hook(f->win, 6, 0, mouse_move, f);
	help();
	mlx_loop(f->mlx);	
	return (0);
}
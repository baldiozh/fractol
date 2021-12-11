/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmckinle <gmckinle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 21:17:52 by gmckinle          #+#    #+#             */
/*   Updated: 2021/12/11 18:30:51 by gmckinle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	zoom_recount(t_fractal *f, int x, int y)
{
	double x_zoomed;
	double y_zoomed;
	
	x_zoomed = f->min.re + x * f->x_step;
	y_zoomed = f->min.im + y * f->y_step;
	f->x_step *= f->zoom;
	f->y_step *= f->zoom;
	f->min.re = x_zoomed + ((f->min.re - x_zoomed) * f->zoom);
	f->min.im = y_zoomed + ((f->min.im - y_zoomed) * f->zoom);
	f->max.re = x_zoomed + ((f->max.re - x_zoomed) * f->zoom);
	f->max.im = y_zoomed + ((f->max.im - y_zoomed) * f->zoom);


	// f->y_step /= f->zoom;
	// f->x_step /= f->zoom;
	// f->min.re = 0 - f->x_step * WIDTH / 2;
	// f->min.im = 0 - f->y_step * HEIGHT / 2;
	// f->max.re = 0 + f->x_step * WIDTH / 2;
	// f->max.im = 0 + f->y_step * HEIGHT / 2;
}

int	mouse_press(int button, int x, int y, t_fractal *f)
{
	(void) x;
	(void) y;
	ft_bzero(f->image.addr, WIDTH * HEIGHT * 4);
	if (button == 4 || button == 5)
	{
		if (button == 4)
			f->zoom += 0.1;
		else if (button == 5)
			f->zoom -= 0.1;
		zoom_recount(f, x, y);
	}
	start_fractal(f);
	return (0);
}

int	mouse_move(int x, int y, t_fractal *f)
{
 	if (f->move && f->stat == 0)
	{
		ft_bzero(f->image.addr, WIDTH * HEIGHT * 4);
		f->k.re = (x - WIDTH / 2) / (0.25 * WIDTH * f->zoom) + f->x_step;
		f->k.im = (y - HEIGHT / 2) / (0.25 * HEIGHT * f->zoom) + f->y_step;
	}
	start_fractal(f);
	return (0);
}

int	red_cross(void)
{
	exit(EXIT_SUCCESS);
}
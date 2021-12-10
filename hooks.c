/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmckinle <gmckinle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 21:17:52 by gmckinle          #+#    #+#             */
/*   Updated: 2021/12/10 19:14:59 by gmckinle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	recount(t_fractal *f, int x, int y)
{
	(void)x;
	(void)y;
	// double x_zoomed;
	// double y_zoomed;
	
	// x_zoomed = x * f->zoom;
	// y_zoomed = y * f->zoom;
	// printf("x %d\n", x);
	// printf("x_zoomed %f\n", x_zoomed);
	// f->y_step /= f->zoom;
	// f->x_step /= f->zoom;
	// f->min.re = (f->min.re - x_zoomed * WIDTH / 2) - x_zoomed;
	
	// f->min.im = (f->min.re - y_zoomed * HEIGHT / 2) - y_zoomed;
	// f->max.re = (f->max.re + x_zoomed * WIDTH / 2) + x_zoomed;
	// f->max.im = (f->max.im + y_zoomed * HEIGHT / 2) + y_zoomed;

	f->y_step /= f->zoom;
	f->x_step /= f->zoom;
	f->min.re = 0 - f->x_step * WIDTH / 2;
	f->min.im = 0 - f->y_step * HEIGHT / 2;
	f->max.re = 0 + f->x_step * WIDTH / 2;
	f->max.im = 0 + f->y_step * HEIGHT / 2;
}

int	mouse_press(int button, int x, int y, t_fractal *f)
{
	(void) x;
	(void) y;
	ft_bzero(f->image.addr, WIDTH * HEIGHT * 4);
	if (button == 4 || button == 5)
	{
		if (button == 4)
			f->zoom *= 1.01;
		else if (button == 5)
			f->zoom /= 1.01;
		recount(f, x, y);
	}
	start_fractal(f);
	return (0);
}

int	mouse_move(int x, int y, t_fractal *f)
{
 	if (f->move)
	{
		ft_bzero(f->image.addr, WIDTH * HEIGHT * 4);
		f->k.im = (y - HEIGHT / 2) / (0.25 * HEIGHT * f->zoom) + f->y_step;
		f->k.re = (x - WIDTH / 2) / (0.25 * WIDTH * f->zoom) + f->x_step;
	}
	start_fractal(f);
	return (0);
}
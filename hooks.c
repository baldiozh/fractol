/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmckinle <gmckinle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 21:17:52 by gmckinle          #+#    #+#             */
/*   Updated: 2021/12/10 15:34:16 by gmckinle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	key_press(int keycode, t_fractal *f)
{
	ft_bzero(f->image.addr, WIDTH * HEIGHT * 4);
	if (keycode == EXIT)
        exit(0);
    else if (keycode == PLUS)
        f->max_iter += 1;
    else if (keycode == MINUS)
        f->max_iter -= 1;
    else if (keycode == UP)
    {
		f->max.im -= f->y_step * 10;
		f->min.im += f->max.im - f->y_step * HEIGHT;
	}
    else if (keycode == DOWN)
	{
		f->max.im += f->y_step * 10;
		f->min.im -= f->max.im - f->y_step * HEIGHT;
	}
    else if (keycode == LEFT)
	{
		f->max.re -= f->x_step * 10;
		f->min.re += f->x_step * 10;
	}
    else if (keycode == RIGHT)
	{
		f->max.re += f->x_step * 10;
		f->min.re -= f->x_step * 10;
	}
    else if (keycode == C)
		f->color_type = (f->color_type + 1) % 3;
	else if (keycode == M)
		f->move = !f->move;
	else if (keycode == R)
	{
		f->min = complex_init(-2.0, -2.0);
		f->max.re = 2.0;
		f->max.im = f->min.im + (f->max.re - f->min.re) * (HEIGHT / WIDTH);
		f->x_step = (f->max.re - f->min.re) / WIDTH;
		f->y_step = (f->max.im - f->min.im) / HEIGHT;
	}
	name_fractal(f);

    return (0);
}

void	recount(t_fractal *f)
{
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
			f->zoom *= 0.99;
		recount(f);
	}
	name_fractal(f);
	return (0);
}

int	mouse_move(int x, int y,t_fractal *f)
{
 	if (f->move)
	{
		ft_bzero(f->image.addr, WIDTH * HEIGHT * 4);
		f->k.im = (y - HEIGHT / 2) / (0.25 * HEIGHT * f->zoom) + f->y_step;
		f->k.re = (x - WIDTH / 2) / (0.25 * WIDTH * f->zoom) + f->x_step;
	}
	name_fractal(f);

	return (0);
}
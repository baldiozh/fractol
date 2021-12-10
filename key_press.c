/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmckinle <gmckinle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 15:36:06 by gmckinle          #+#    #+#             */
/*   Updated: 2021/12/10 15:40:15 by gmckinle         ###   ########.fr       */
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
	start_fractal(f);
    return (0);
}
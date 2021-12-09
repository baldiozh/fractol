/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmckinle <gmckinle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 21:17:52 by gmckinle          #+#    #+#             */
/*   Updated: 2021/12/09 16:55:28 by gmckinle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	key_press(int keycode, t_fractal *f)
{
    (void)f;
    
	if (keycode == EXIT)
        exit(0);
    else if (keycode == PLUS)
        f->max_iter += 1;
    else if (keycode == MINUS)
        f->max_iter -= 1;
    else if (keycode == UP)
        f->y_step -= 1.0 / f->zoom;
    else if (keycode == DOWN)
        f->y_step += 1.0 / f->zoom;
    else if (keycode == LEFT)
        f->x_step -= 1.0 / f->zoom;
    else if (keycode == RIGHT)
        f->x_step += 1.0 / f->zoom;
    else if (keycode == C)
	{
		if (f->color_type == 2)
			f->color_type = 0;
		else
			f->color_type += 1;
	}

    return (0);
}

int	mouse_press(int button, t_fractal *f)
{
	ft_bzero(f->image.addr, WIDTH * HEIGHT * f->image.bits_per_pixel);
	if (button == 4)
	{
		f->zoom *= 1.50;
		f->y_step += (f->y - HEIGHT / 2) * 0.0020 / f->zoom;
		f->x_step += (f->x - WIDTH / 2) * 0.0020 / f->zoom;
	}
	else if (button == 5)
	{
		f->y_step += (f->y - HEIGHT / 2) * 0.0020 / f->zoom;
		f->x_step += (f->x - WIDTH / 2) * 0.0020 / f->zoom;
		f->zoom *= 0.5;
	}
	// name_fractal(f);
	return (0);
}

int	mouse_move(t_fractal *f)
{
	ft_bzero(f->image.addr, WIDTH * HEIGHT * f->image.bits_per_pixel);
	f->c.im = (f->y - HEIGHT / 2) / (0.25 * HEIGHT * f->zoom) + f->y_step;
	f->c.re = (f->x - WIDTH / 2) / (0.25 * WIDTH * f->zoom) + f->x_step;
	julia(f);
	return (0);
}
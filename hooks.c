/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmckinle <gmckinle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 21:17:52 by gmckinle          #+#    #+#             */
/*   Updated: 2021/12/06 20:27:56 by gmckinle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	key_press(int keycode, t_fractal *f)
{
    (void)f;
    
	if (keycode == 53)
        exit(0);
    else if (keycode == 24)
        f->max_iter += 1;
    else if (keycode == 27)
        f->max_iter -= 1;
    else if (keycode == 4)
        help_win(f);
    else if (keycode == 126)
        f->y_step -= 1.0;
    else if (keycode == 125)
        f->y_step += 1.0;
    else if (keycode == 123)
        f->x_step -= 1.0;
    else if (keycode == 124)
        f->x_step += 1.0;
    //zoom
    //move
    //

    return (0);
}

int	mouse_press(int button, t_fractal *f)
{
	ft_bzero(f->image.addr, WIDTH * HEIGHT * f->image.bits_per_pixel);
	if (button == 4)
	{
		f->zoom *= 1.25;
		f->y_step += (f->y - HEIGHT / 2) * 0.0015 / f->zoom;
		f->x_step += (f->x - WIDTH / 2) * 0.0015 / f->zoom;
	}
	else if (button == 5)
	{
		f->y_step += (f->y - HEIGHT / 2) * 0.0015 / f->zoom;
		f->x_step += (f->x - WIDTH / 2) * 0.0015 / f->zoom;
		f->zoom *= 0.8;
	}
	name_fractal(f);
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
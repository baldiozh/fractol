/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmckinle <gmckinle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 21:17:52 by gmckinle          #+#    #+#             */
/*   Updated: 2021/12/06 17:21:29 by gmckinle         ###   ########.fr       */
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
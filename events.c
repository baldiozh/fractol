/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmckinle <gmckinle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 20:18:58 by gmckinle          #+#    #+#             */
/*   Updated: 2021/11/25 20:46:11 by gmckinle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void    events(t_fractal *f, void (*func)(void))
{
    mlx_hook(f->win, 2, 0, func, f);
    mlx_loop(f->mlx);
    
}

void     close(int keycode, t_fractal *f)
{
    mlx_destroy_window(f->mlx, f->win);
}
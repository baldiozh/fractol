/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmckinle <gmckinle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 21:36:39 by gmckinle          #+#    #+#             */
/*   Updated: 2021/12/09 16:56:50 by gmckinle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void    help()
{
    ft_putstr_fd("\x1b[1;32m------------------------------------\n", 1);
    ft_putstr_fd("\x1b[32m-*-*-  KEYS FOR USING PROGRAM  -*-*-\n", 1);
    ft_putstr_fd("\x1b[32m-*- Moves          [←][↑][↓][→]  -*-\n", 1);
    ft_putstr_fd("\x1b[32m-*- Iterations     [-][+]        -*-\n", 1);
    ft_putstr_fd("\x1b[32m-*- Color          [C]           -*-\n", 1);
    ft_putstr_fd("\x1b[32m-*- Exit           [esc]         -*-\n", 1);
    ft_putstr_fd("\x1b[32m------------------------------------\n", 1);
    
}

void    help_win(t_fractal *f)
{
    mlx_string_put(f->mlx, f->win, 720, 830, 0xfffafa, "Iterations       [-][+]");
    mlx_string_put(f->mlx, f->win, 720, 845, 0xfffafa, "Exit             [esc] ");
    //delete help from screen
}
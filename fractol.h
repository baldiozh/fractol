/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmckinle <gmckinle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 17:54:30 by gmckinle          #+#    #+#             */
/*   Updated: 2021/10/07 15:25:27 by gmckinle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <math.h>
# include "mlx/mlx.h"
# include <unistd.h>
# include <stdlib.h>

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_image;

typedef struct	s_complex {
	double	im;
	double	re;
}				t_complex;

typedef struct	s_fractal {
	void	*win;
	void	*mlx;
	t_image	img;
	t_complex	C;
	t_complex	Z;
	t_complex	min;
	t_complex	max;
	int			max_iter;
	
}				t_fractal;

#endif

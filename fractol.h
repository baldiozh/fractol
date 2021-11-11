/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmckinle <gmckinle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 17:54:30 by gmckinle          #+#    #+#             */
/*   Updated: 2021/11/11 18:59:33 by gmckinle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define WIGHT 800
# define HEIGHT 800

# include <math.h>
# include "mlx/mlx.h"
# include <unistd.h>
# include <stdlib.h>

# include <stdio.h>

typedef struct	s_image {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_image;

// typedef struct	s_complex {
// 	double	im;
// 	double	re;
// }				t_complex;

typedef struct	s_fractal {
	void		*win;
	void		*mlx;
	t_image		img;
	char		*name;
	int			i;
	int			x;
	int			y;
	double		c_re;
	double		c_im;
	double		z_re;
	double		z_im;
	int			max_iter;
	
}				t_fractal;

/* libft */
void	ft_putstr(char *s);
int		ft_strncmp(const char *str1, const char *str2, size_t n);

/* */



#endif

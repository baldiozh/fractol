/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmckinle <gmckinle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 17:26:51 by gmckinle          #+#    #+#             */
/*   Updated: 2021/11/11 18:10:47 by gmckinle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		CheckingIfBelongsToQuantity(t_complex complex) //и чооооо????? никаких действий толковых кроме условий
{
	int		Z;
	int		F;

	Z = 0;
	while (F < 5)
	{
		printf("!!!\n"); // infinity loop
		if (complex.re >= 0)
			F = Z*Z + complex.re;
		else 
			F = Z*Z - complex.re;
		
	}
	// if (F > 5)
	// 	return (1);
	return (0);
}
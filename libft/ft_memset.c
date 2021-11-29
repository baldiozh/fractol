/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmckinle <gmckinle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 17:27:42 by gmckinle          #+#    #+#             */
/*   Updated: 2021/11/29 17:27:43 by gmckinle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *dest, int c, size_t n)
{
	size_t	i;
	char	*src;

	i = 0;
	src = dest;
	while (i < n)
	{
		*src++ = c;
		i++;
	}
	return (dest);
}

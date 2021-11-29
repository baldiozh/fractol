/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmckinle <gmckinle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 17:27:30 by gmckinle          #+#    #+#             */
/*   Updated: 2021/11/29 17:27:31 by gmckinle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy (void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*d;
	unsigned char	*s;

	i = 0;
	s = (unsigned char *)src;
	d = (unsigned char *)dest;
	if (dest == NULL && src == NULL)
		return (NULL);
	while (i < n)
	{
		*d++ = *s++;
		i++;
	}
	return (dest);
}

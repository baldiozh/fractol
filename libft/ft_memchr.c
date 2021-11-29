/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmckinle <gmckinle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 17:27:23 by gmckinle          #+#    #+#             */
/*   Updated: 2021/11/29 17:27:24 by gmckinle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memchr(const void *arr, int c, size_t n)
{
	size_t	i;
	char	sym;
	char	*a;

	i = 0;
	a = (char *)arr;
	sym = c;
	while (i < n)
	{
		if (a[i] == sym)
			return (&a[i]);
		i++;
	}
	return (NULL);
}

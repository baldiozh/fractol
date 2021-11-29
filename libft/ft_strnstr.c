/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmckinle <gmckinle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 17:31:28 by gmckinle          #+#    #+#             */
/*   Updated: 2021/11/29 17:31:29 by gmckinle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_work(char *h, char *n, size_t len, size_t nlen)
{
	size_t	i;

	i = 0;
	while (*h != '\0')
	{
		if (ft_memcmp(n, h, nlen) == 0 && *h != '\0')
			return (h);
		else if (i == (int)len - nlen)
			return (NULL);
		h++;
		i++;
	}
	return (0);
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	nlen;
	char	*h;
	char	*n;

	i = 0;
	h = (char *)haystack;
	n = (char *)needle;
	nlen = ft_strlen(n);
	if (*h == 0 && *n == 0)
		return ((void *)h);
	if (*n == 0 && *h != 0)
		return (h);
	if (len < 0)
		len = ft_strlen(h);
	if (i <= (len - nlen) && *n && *h && len != 0)
		return (ft_work(h, n, len, nlen));
	return (NULL);
}

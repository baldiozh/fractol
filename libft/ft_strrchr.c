/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmckinle <gmckinle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 17:31:25 by gmckinle          #+#    #+#             */
/*   Updated: 2021/11/29 17:31:26 by gmckinle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int ch)
{
	size_t	i;
	size_t	len;
	char	*s;

	i = 0;
	s = (char *)str;
	len = ft_strlen(str);
	if (ch == '\0')
		return ((char *)(s + len));
	while (len > 0)
	{
		if (s[len] == (char)ch)
			return (s + len);
		len--;
	}
	if (s[len] != (char)ch)
		return (NULL);
	return (s);
}

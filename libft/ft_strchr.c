/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmckinle <gmckinle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 17:31:59 by gmckinle          #+#    #+#             */
/*   Updated: 2021/11/29 17:32:00 by gmckinle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int ch)
{
	size_t	i;
	size_t	len;
	char	*s;

	i = 0;
	s = (char *)str;
	len = ft_strlen(str);
	if (ch == '\0')
		return ((char *)(s + len));
	while (i <= len && s[i] != '\0')
	{
		if (s[i] == (char)ch)
			return (s + i);
		i++;
	}
	if (s[i] != (char)ch)
		return (NULL);
	return (s);
}

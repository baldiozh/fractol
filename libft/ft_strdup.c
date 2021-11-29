/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmckinle <gmckinle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 17:31:41 by gmckinle          #+#    #+#             */
/*   Updated: 2021/11/29 17:31:42 by gmckinle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char *src)
{
	char	*str;
	size_t	len;
	char	*p;

	len = ft_strlen(src);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	p = str;
	while (*src)
		*(p++) = *(src++);
	*p = '\0';
	return (str);
}

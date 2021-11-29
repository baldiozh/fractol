/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmckinle <gmckinle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 17:26:52 by gmckinle          #+#    #+#             */
/*   Updated: 2021/11/29 17:26:53 by gmckinle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t num, size_t size)
{
	char	*buf;

	if (num >= 0 && size >= 0)
	{
		buf = (char *)malloc(sizeof(char) * (size * num));
		if (!buf)
			return (NULL);
		ft_bzero(buf, size * num);
		return (buf);
	}
	return (NULL);
}

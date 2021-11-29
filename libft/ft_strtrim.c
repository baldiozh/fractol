/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmckinle <gmckinle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 17:31:19 by gmckinle          #+#    #+#             */
/*   Updated: 2021/11/29 17:31:20 by gmckinle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_find(char c, const char *set)
{
	size_t	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static char	*ft_record(const char *s1, char *str, size_t i, size_t len)
{
	size_t	j;

	j = 0;
	while (j < len)
	{
		str[j] = s1[i];
		j++;
		i++;
	}
	str[j] = '\0';
	return (str);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	len;
	size_t	slen;
	char	*str;

	i = 0;
	if (!s1)
		return (NULL);
	slen = ft_strlen(s1);
	while (i < slen && ft_find(s1[i], set) != 0)
		i++;
	while (slen > i && ft_find(s1[slen - 1], set) != 0)
		slen--;
	len = slen - i;
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	return (ft_record(s1, str, i, len));
}

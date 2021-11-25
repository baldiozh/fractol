#include "libft.h"

size_t	ft_strlcpy (char *dest, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (!dest || !src)
		return (0);
	if (dstsize <= 0)
		return (ft_strlen(src));
	while (i < (dstsize - 1) && src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (ft_strlen(src));
}

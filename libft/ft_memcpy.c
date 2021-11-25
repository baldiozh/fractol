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

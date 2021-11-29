#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	unsigned char	*d;
	unsigned char	*s;

	d = (unsigned char *)dest;
	s = (unsigned char *)src;
	if (d > s)
		while (len-- > 0)
			*(d + len) = *(s + len);
	else
		return (ft_memcpy(dest, src, len));
	return (dest);
}

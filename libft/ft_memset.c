#include "libft.h"

void	*ft_memset(void *dest, int c, size_t n)
{
	size_t	i;
	char	*src;

	i = 0;
	src = dest;
	while (i < n)
	{
		*src++ = c;
		i++;
	}
	return (dest);
}

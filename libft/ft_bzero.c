#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t		i;
	char		*src;

	i = 0;
	src = s;
	while (i < n)
	{
		*src = '\0';
		src++;
		i++;
	}
}

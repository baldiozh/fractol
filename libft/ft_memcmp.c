#include "libft.h"

int	ft_memcmp(const void *arr1, const void *arr2, size_t n)
{
	size_t		i;
	const char	*a1;
	const char	*a2;

	i = 0;
	a1 = arr1;
	a2 = arr2;
	while (i < n)
	{
		if (a1[i] != a2[i])
			return ((unsigned char)a1[i] - (unsigned char)a2[i]);
		i++;
	}
	return (0);
}

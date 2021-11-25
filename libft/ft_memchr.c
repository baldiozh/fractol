#include <stddef.h>

void	*ft_memchr(const void *arr, int c, size_t n)
{
	size_t	i;
	char	sym;
	char	*a;

	i = 0;
	a = (char *)arr;
	sym = c;
	while (i < n)
	{
		if (a[i] == sym)
			return (&a[i]);
		i++;
	}
	return (NULL);
}

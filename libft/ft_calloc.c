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

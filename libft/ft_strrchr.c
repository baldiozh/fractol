#include "libft.h"

char	*ft_strrchr(const char *str, int ch)
{
	size_t	i;
	size_t	len;
	char	*s;

	i = 0;
	s = (char *)str;
	len = ft_strlen(str);
	if (ch == '\0')
		return ((char *)(s + len));
	while (len > 0)
	{
		if (s[len] == (char)ch)
			return (s + len);
		len--;
	}
	if (s[len] != (char)ch)
		return (NULL);
	return (s);
}

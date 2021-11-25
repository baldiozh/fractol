#include "libft.h"

char	*ft_strchr(const char *str, int ch)
{
	size_t	i;
	size_t	len;
	char	*s;

	i = 0;
	s = (char *)str;
	len = ft_strlen(str);
	if (ch == '\0')
		return ((char *)(s + len));
	while (i <= len && s[i] != '\0')
	{
		if (s[i] == (char)ch)
			return (s + i);
		i++;
	}
	if (s[i] != (char)ch)
		return (NULL);
	return (s);
}

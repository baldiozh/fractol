#include "libft.h"

static char	*ft_min_i(const char *str, int n)
{
	if (n == INT_MIN)
		str = ft_strdup("-2147483648");
	return ((char *)str);
}

static int	ft_des(int n)
{
	int	des;

	des = 1;
	while (n / 10)
	{
		n /= 10;
		des *= 10;
	}
	return (des);
}

static int	ft_count(int n)
{
	int	len;

	len = 0;
	while (n / 10)
	{
		len++;
		n /= 10;
	}
	return (len + 1);
}

static char	ft_big(char *str, int n, int len, int i)
{
	int	des;

	des = ft_des(n);
	while (i != len)
	{
		str[i++] = (n / des) + '0';
		n = n % des;
		des /= 10;
	}
	str[i] = '\0';
	return (*str);
}

char	*ft_itoa(int n)
{
	int		i;
	int		len;
	char	*str;

	i = 0;
	len = ft_count(n);
	if (n == INT_MIN)
		return (ft_min_i(str, n));
	if (n < 0)
		len += 1;
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	if (n < 0)
	{
		n = -n;
		str[i++] = '-';
	}
	if (ft_isdigit(n) == 1)
	{
		str[i] = n + '0';
		str[i + 1] = '\0';
	}
	ft_big(str, n, len, i);
	return (str);
}

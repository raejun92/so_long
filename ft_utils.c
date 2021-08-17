#include "ft_so_long.h"

void	error_msg(void)
{
	write(2, "Error\n", 6);
	exit(0);
}

int	ft_strlen(const char *s)
{
	int i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *s1)
{
	int		l;
	int		i;
	char	*str;

	l = ft_strlen(s1);
	if (!(str = (char *)malloc(sizeof(char) * (l + 1))))
		return (0);
	i = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	src_l;

	src_l = 0;
	i = 0;
	if (!dst || !src)
		return (0);
	while (src[src_l])
		src_l++;
	if (dstsize == 0)
		return (src_l);
	while (src[i] != '\0' && i + 1 < dstsize)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (src_l);
}

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dst_l;
	size_t	src_l;
	size_t	i;

	i = 0;
	dst_l = ft_strlen(dst);
	src_l = ft_strlen(src);
	if (dstsize == 0)
		return (src_l);
	if (dstsize <= dst_l)
		return (src_l + dstsize);
	while (dst_l + i + 1 < dstsize && src[i])
	{
		dst[dst_l + i] = src[i];
		i++;
	}
	dst[dst_l + i] = '\0';
	return (src_l + dst_l);
}
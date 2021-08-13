#include "ft_so_long.h"

void	error_msg(void)
{
	write(2, "Error\n", 6);
	exit(0);
}

size_t	ft_strlen(const char *s)
{
	size_t i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
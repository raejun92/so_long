#include "ft_so_long.h"

// 기능: 맵 이름이 .ber로 끝나는 지 확인, 리턴: .ber이면 1, 아니면 0
int	check_map_name(char *argv)
{
	int len;

	len = ft_strlen(argv);
	if (argv[len - 1] != 'r')
		return (0);
	if (argv[len - 2] != 'e')
		return (0);
	if (argv[len - 3] != 'b')
		return (0);
	if (argv[len - 4] != '.')
		return (0);
	return (1);
}

// 기능: 인수로 넣은 맵내용을 game구조체에 저장, 리턴: void
void	map_parse(t_game *game, char *argv)
{
	int		fd;
	char	buf[2];
	char	*tmp;
	char	*chunk;

	fd = open(argv, O_RDONLY); 
	if (fd < 0)
		error_msg();
	tmp = ft_strdup("");
	while (read(fd, buf, 1) > 0)
	{
		buf[1] = '\0';
		chunk = ft_strjoin(tmp, buf);
		free(tmp);
		tmp = chunk;
	}
	game->map = ft_split(tmp, '\n');
	free(tmp);
}
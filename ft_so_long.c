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

// 기능: game 구조체 초기화, 리턴: void
void	init_game(t_game *game)
{
	game->mlx = mlx_init();
	game->win = 0;
	game->img = 0;
	game->cnt = 0;
	game->img_width = 0;
	game->img_height = 0;
	game->map = 0;
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
	while (*game->map != NULL)
	{
		printf("%s\n", *game->map);
		game->map++;
	}
}

// 기능: 파싱한 맵이 정상적인 맵인지 확인, 리턴: void
void	validate_map(t_game *game)
{
	// 맵이 1로 둘러 쌓여 직사각형인지 확인
	// 맵에 P,C,E 하나이상인지 확인
}

int	main(int argc, char **argv)
{
	t_game	game;
	
	if (argc != 2 || !check_map_name(*(++argv)))
		error_msg();
	init_game(&game);
	map_parse(&game, *argv);
	validate_map(&game);
	return (0);
}

/* 
TODO
1. 맵 파싱
2. 맵에 따라 그리기
3. 캐릭터 움직임
4. 벽 안 움직임 (노 스왑)
5. 아이템 먹기 
6. 탈출하기 (아이템 다 먹었을 경우)
 */

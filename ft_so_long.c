#include "ft_so_long.h"

// 기능: game 구조체 초기화, 리턴: void
void	init_game(t_game *game)
{
	game->mlx = mlx_init();
	game->win = 0;
	game->img = 0;
	game->cnt = 0;
	game->win_width = 400;
	game->win_height = 160;
	game->img_width = 0;
	game->img_height = 0;
	game->map = 0;
}

// 기능: 파싱한 맵이 정상적인 맵인지 확인, 리턴: void
void	validate_map(t_game game)
{
	// 맵이 1로 둘러 쌓여있는 직사각형인지 확인 -> 모든 라인의 개수가 똑같은지 확인해야 함
	check_rectangle(game.map);
	check_wall(game.map);
	// 맵에 다른 요소가 있는지 확인
	check_other_element(game.map);
	// 맵에 P,C,E 하나이상인지 확인
	check_element(game.map);
}

// 기능: 바닥 그리기, 리턴: void
void	set_floor(t_game *game)
{
	int	i;
	int	j;

	game->img = mlx_xpm_file_to_image(game->mlx, "./img/0.xpm", &game->img_width, &game->img_height);
	i = 0;
	while (i < game->win_height)
	{
		j = 0;
		while (j < game->win_width)
		{
			mlx_put_image_to_window(game->mlx, game->win, game->img, j, i);
			j += 40;
		}
		i += 40;
	}
}

void	set_wall(t_game *game)
{
	int	i;
	int	j;
	int	a;
	int	b;

	game->img = mlx_xpm_file_to_image(game->mlx, "./img/1.xpm", &game->img_width, &game->img_height);
	a = 0;
	i = 0;
	while (i < game->win_height)
	{
		j = 0;
		b = 0;
		while (j < game->win_width)
		{
			if (game->map[a][b] == '1')
				mlx_put_image_to_window(game->mlx, game->win, game->img, j, i);
			j += 40;
			b++;
		}
		i += 40;
		a++;
	}
}

// 기능: 아이템 그리기, 리턴: void
void	set_item(t_game *game)
{
	int	i;
	int	j;
	int	a;
	int	b;

	game->img = mlx_xpm_file_to_image(game->mlx, "./img/C.xpm", &game->img_width, &game->img_height);
	a = 0;
	i = 0;
	while (i < game->win_height)
	{
		j = 0;
		b = 0;
		while (j < game->win_width)
		{
			if (game->map[a][b] == 'C')
				mlx_put_image_to_window(game->mlx, game->win, game->img, j, i);
			j += 40;
			b++;
		}
		i += 40;
		a++;
	}
}

// 기능: 캐릭터 그리기, 리턴: void
void	set_player(t_game *game)
{
	int	i;
	int	j;
	int	a;
	int	b;

	game->img = mlx_xpm_file_to_image(game->mlx, "./img/P.xpm", &game->img_width, &game->img_height);
	a = 0;
	i = 0;
	while (i < game->win_height)
	{
		j = 0;
		b = 0;
		while (j < game->win_width)
		{
			if (game->map[a][b] == 'P')
				mlx_put_image_to_window(game->mlx, game->win, game->img, j, i);
			j += 40;
			b++;
		}
		i += 40;
		a++;
	}
}

// 기능: 출구 그리기, 리턴: void
void	set_exit(t_game *game)
{
	int	i;
	int	j;
	int	a;
	int	b;

	game->img = mlx_xpm_file_to_image(game->mlx, "./img/E.xpm", &game->img_width, &game->img_height);
	a = 0;
	i = 0;
	while (i < game->win_height)
	{
		j = 0;
		b = 0;
		while (j < game->win_width)
		{
			if (game->map[a][b] == 'E')
				mlx_put_image_to_window(game->mlx, game->win, game->img, j, i);
			j += 40;
			b++;
		}
		i += 40;
		a++;
	}
}

// 기능: 게임화면 그리기, 리턴: void
void	draw_map(t_game *game)
{
	game->win = mlx_new_window(game->mlx, game->win_width, game->win_height, "so_long");
	set_floor(game);
	set_wall(game);
	set_item(game);
	set_player(game);
	set_exit(game);
	mlx_loop(game->mlx);
}

int	main(int argc, char **argv)
{
	t_game	game;
	
	if (argc != 2 || !check_map_name(*(++argv)))
		error_msg();
	init_game(&game);
	map_parse(&game, *argv);
	validate_map(game);
	draw_map(&game);

	// system("leaks a.out > leaks_result_temp; cat leaks_result_temp | grep leaked && rm -rf leaks_result_temp");
	return (0);
}

/* 
TODO
1. 맵 파싱 [v]
2. 맵에 따라 그리기
3. 캐릭터 움직임 (스왑)
4. 벽 안 움직임 (노 스왑)
5. 아이템 먹기 
6. 탈출하기 (아이템 다 먹었을 경우)
 */

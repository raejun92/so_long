#include "ft_so_long.h"

// 기능: game 구조체 초기화, 리턴: void
void	init_game(t_game *game)
{
	game->mlx = mlx_init();
	game->win = 0;
	game->img = 0;
	game->move_cnt = 0;
	game->win_width = 400;
	game->win_height = 200;
	game->img_width = 0;
	game->img_height = 0;
	game->item_cnt = 0;
	game->map = 0;
}

// 기능: 아이템 개수 초기화, 리턴: void
void	init_item_cnt(t_game *game)
{
	int		i;
	char	**tmp;

	tmp = game->map;
	while (*tmp != NULL)
	{
		i = 0;
		while ((*tmp)[i] != '\0')
		{
			if ((*tmp)[i] == 'C')
				game->item_cnt++;
			i++;
		}
		tmp++;
	}
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

// 기능: 게임화면 그리기, 리턴: void
int	draw_map(t_game *game)
{
	set_floor(game);
	set_wall(game);
	set_item(game);
	set_player(game);
	set_exit(game);
	return (1);
}

int	main(int argc, char **argv)
{
	t_game	game;
	
	if (argc != 2 || !check_map_name(*(++argv)))
		error_msg();
	init_game(&game);
	game.win = mlx_new_window(game.mlx, game.win_width, game.win_height, "so_long");
	map_parse(&game, *argv);
	validate_map(game);
	mlx_loop_hook(game.mlx, &draw_map, &game);
	init_item_cnt(&game);
	process_event(&game);
	mlx_loop(game.mlx);
	return (0);
}

/* TODO
맵 엔터 처리
맵 빈파일
윈도우 크기 동적
 */
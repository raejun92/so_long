#include "ft_so_long.h"

// 기능: game 구조체 초기화, 리턴: void
void	init_game(t_game *game)
{
	game->mlx = mlx_init();
	game->win = 0;
	game->img = 0;
	game->move_cnt = 0;
	game->win_width = 400;
	game->win_height = 160;
	game->img_width = 0;
	game->img_height = 0;
	game->item_cnt = 0;
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

// 기능: 게임화면 그리기, 리턴: void
void	draw_map(t_game *game)
{
	set_floor(game);
	set_wall(game);
	set_item(game);
	set_player(game);
	set_exit(game);
}

// 기능: player위에 어떤 요소가 있는지 확인, 리턴: char 0,1,E,C중 하나
static char	key_w_check_element(char **map, t_move *move)
{
	char	**tmp;
	int		i;
	int		j;

	tmp = map;
	i = 0;
	while (*tmp != NULL)
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (map[i][j] == 'P')
			{
				move->move_width = i;
				move->move_height = j;
				return (map[i - 1][j]);
			}
			j++;
		}
		i++;
		tmp++;
	}
	return (0);
}

// 기능: player가 위로 이동, 리턴: void
static void	key_w_move(char **map, t_move move)
{
	char	tmp;

	tmp = map[move.move_width][move.move_height];
	map[move.move_width][move.move_height] = map[move.move_width - 1][move.move_height];
	map[move.move_width - 1][move.move_height] = tmp;
}

// 기능: player가 아이템으로 이동 후 아이템 삭제, 리턴: void
static void	key_w_get_item(char **map, t_move move)
{
	map[move.move_width - 1][move.move_height] = map[move.move_width][move.move_height];
	map[move.move_width][move.move_height] = '0';
	
}

// 기능: player가 출구로 이동 후 게임 종료, 리턴: void
static void	key_w_exit(char **map, t_move move)
{
	map[move.move_width - 1][move.move_height] = map[move.move_width][move.move_height];
	map[move.move_width][move.move_height] = '0';
	// 아이템이 0면 종료
	exit(0);
}

// 기능: player위로 이동, 리턴: void
void	key_w_handler(char **map) // TODO: map을 game으로 바꿔야 함
{
	char	element;
	t_move	move;
	
	move.move_width = 0;
	move.move_height = 0;
	// 현재 맵에서 플레이어 위치를 확인
	element = key_w_check_element(map, &move);
	if (element == '1')
		return ;
	else if (element == '0')
		key_w_move(map, move);
	else if (element == 'C')
		key_w_get_item(map, move);
	else if (element == 'E')
		key_w_exit(map, move);
	// element 요소에 따라 처리
	// 플레이어 위에 1이 있으면 이동하지 않음
	// 0이라면 이동 가능
	// C라면 아이템 그림을 삭제 후 아이템 먹은 표시
	
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
	draw_map(&game);
	process_event(&game);
	mlx_loop(game.mlx);
	// system("leaks a.out > leaks_result_temp; cat leaks_result_temp | grep leaked && rm -rf leaks_result_temp");
	return (0);
}

/* 
TODO
1. 맵 파싱 [v]
2. 맵에 따라 그리기 [v]
3. 캐릭터 움직임 (스왑)
4. 벽 안 움직임 (노 스왑)
5. 아이템 먹기 
6. 탈출하기 (아이템 다 먹었을 경우)
 */

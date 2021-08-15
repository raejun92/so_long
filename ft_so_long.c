#include "ft_so_long.h"

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

int	main(int argc, char **argv)
{
	t_game	game;
	
	if (argc != 2 || !check_map_name(*(++argv)))
		error_msg();
	init_game(&game);
	map_parse(&game, *argv);
	validate_map(game);
	// draw_map(&game);

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

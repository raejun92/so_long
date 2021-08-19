#include "ft_so_long.h"

// 기능: 파싱한 맵이 정상적인 맵인지 확인, 리턴: void
void	validate_map(t_game game)
{
	if (*game.map == NULL) // 맵이 비어 있을 경우 예외처리
	{
		free_malloc(game.map);
		error_msg();
	}
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
	map_parse(&game, *argv);
	validate_map(game);
	init_window(&game);
	mlx_loop_hook(game.mlx, &draw_map, &game);
	init_item_cnt(&game);
	process_event(&game);
	mlx_loop(game.mlx);
	return (0);
}
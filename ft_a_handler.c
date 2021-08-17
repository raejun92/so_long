#include "ft_so_long.h"

#include "ft_so_long.h"

#include "ft_so_long.h"

// 기능: player위에 어떤 요소가 있는지 확인, 리턴: char 0,1,E,C중 하나
static char	key_check_element(char **map, t_move *move)
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
				return (map[i][j - 1]);
			}
			j++;
		}
		i++;
		tmp++;
	}
	return (0);
}

// 기능: player가 위로 이동, 리턴: void
static void	key_move(t_game *game, t_move move)
{
	char	tmp;

	tmp = game->map[move.move_width][move.move_height];
	game->map[move.move_width][move.move_height] = game->map[move.move_width][move.move_height - 1];
	game->map[move.move_width][move.move_height - 1] = tmp;
	game->move_cnt++;
}

// 기능: player가 아이템으로 이동 후 아이템 삭제, 리턴: void
static void	key_get_item(t_game *game, t_move move)
{
	game->map[move.move_width][move.move_height - 1] = game->map[move.move_width][move.move_height];
	game->map[move.move_width][move.move_height] = '0';
	game->move_cnt++;
	game->item_cnt--;
}

// 기능: player가 출구로 이동 후 게임 종료, 리턴: void
static void	key_exit(t_game *game)
{
	if (game->item_cnt == 0)
		exit(0);
}

// 기능: player위로 이동, 리턴: void
void	key_a_handler(t_game *game)
{
	char	element;
	t_move	move;

	move.move_width = 0;
	move.move_height = 0;
	// 현재 맵에서 플레이어 위치를 확인
	element = key_check_element(game->map, &move);
	if (element == '1')
		return ;
	else if (element == '0')
		key_move(game, move);
	else if (element == 'C')
		key_get_item(game, move);
	else if (element == 'E')
		key_exit(game);
	draw_map(game);
	// element 요소에 따라 처리
	// 플레이어 위에 1이 있으면 이동하지 않음
	// 0이라면 이동 가능
	// C라면 아이템 그림을 삭제 후 아이템 먹은 표시
	
}
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
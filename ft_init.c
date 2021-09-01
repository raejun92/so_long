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


// 기능: window 가로 길이, 리턴: int window의 width 길이
static int	init_width(char **map)
{
	int	len;

	len = ft_strlen(*map);
	return (len);
}

// 기능: window 세로 길이, 리턴: int window의 height
static int	init_height(char **map)
{
	int	len;

	len = 0;
	while (*map != NULL)
	{
		len++;
		map++;
	}
	return (len);
}

// 가능: 화면(window) 설정, 리턴: void
void	init_window(t_game *game)
{
	game->win_width = init_width(game->map) * 40;
	game->win_height = init_height(game->map) * 40;
	game->win = mlx_new_window(game->mlx, game->win_width, game->win_height, "so_long");
}
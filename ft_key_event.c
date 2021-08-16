#include "ft_so_long.h"

// 기능: W,S,A,D,ESC 이벤트 처리, 리턴: int
int	key_press(int key, t_game *game)
{
	if (key == KEY_W)
		printf("up\n");
	else if (key == KEY_S)
		printf("down\n");
	else if (key == KEY_A)
		printf("left\n");
	else if (key == KEY_D)
		printf("right\n");
	else if (key == KEY_ESC)
		exit(0);
	return (0);
}

int	click_x(t_game *game)
{
	exit(0);
}

void	process_event(t_game *game)
{
	mlx_hook(game->win, X_EVENT_KEY_PRESS, 0, &key_press, game);
	mlx_hook(game->win, X_EVENT_KEY_EXIT, 0, &click_x, game);
}
#include "ft_so_long.h"

// 기능: W,S,A,D,ESC 이벤트 처리, 리턴: int
int	key_press(int key, t_game *game)
{
	if (key == KEY_W)
		key_w_handler(game);
	else if (key == KEY_S)
		key_s_handler(game);
	else if (key == KEY_A)
		key_a_handler(game);
	else if (key == KEY_D)
		key_d_handler(game);
	else if (key == KEY_ESC)
		exit(0);
	if (key == KEY_W || key == KEY_S || key == KEY_A || key == KEY_D)
		printf("%d\n", game->move_cnt);
	return (0);
}

// 기능: 창의 x버튼으로 프로그램 중지, 리턴: int
int	click_x(t_game *game)
{
	exit(0);
}

// 기능: 이벤트 키 처리, 리턴: void
void	process_event(t_game *game)
{
	mlx_hook(game->win, X_EVENT_KEY_PRESS, 0, &key_press, game);
	mlx_hook(game->win, X_EVENT_KEY_EXIT, 0, &click_x, game);
}
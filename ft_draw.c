#include "ft_so_long.h"

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

// 기능: 벽 그리기, 리턴: void
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
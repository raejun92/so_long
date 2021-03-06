#ifndef FT_SO_LONG_H
# define FT_SO_LONG_H

# include <stdlib.h>
#include <fcntl.h> // open
#include <unistd.h> // read, write, close
#include <stdio.h>
#include "./mlx/mlx.h"

#define X_EVENT_KEY_PRESS	2 // mlx_hook event key
#define X_EVENT_KEY_EXIT	17 //exit key code
#define KEY_ESC	53
#define KEY_A	0
#define KEY_W	13
#define KEY_S	1
#define KEY_D	2

typedef struct s_game {
	void	*mlx;
	void	*win;
	void	*img;
	int		move_cnt;
	int		win_width;
	int		win_height;
	int		img_width;
	int 	img_height;
	int		item_cnt;
	char	**map;
}t_game;

typedef struct s_move {
	int		move_width;
	int		move_height;
}t_move;

/* ft_so_long.c */
int	draw_map(t_game *game);

/* ft_utils.c */
void	error_msg(void);
int	ft_strlen(const char *s);
char	*ft_strdup(const char *s1);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);


/* ft_utils2.c */
char	*ft_strjoin(char const *s1, char const *s2);
char	**ft_split(char const *s, char c);
char	**free_malloc(char **str);

/* ft_parse.c */
int	check_map_name(char *argv);
void	map_parse(t_game *game, char *argv);

/* ft_check_map.c */
void	check_rectangle(char **map);
void	check_wall(char **map);
void	check_other_element(char **map);
void	check_element(char **map);

/* ft_draw.c */
void	set_floor(t_game *game);
void	set_wall(t_game *game);
void	set_item(t_game *game);
void	set_player(t_game *game);
void	set_exit(t_game *game);

/* ft_key_event.c */
int	key_press(int key, t_game *game);
int	click_x(void);
void	process_event(t_game *game);

/* ft_w_handler.c */
void	key_w_handler(t_game *game);

/* ft_s_handler.c */
void	key_s_handler(t_game *game);

/* ft_a_handler.c */
void	key_a_handler(t_game *game);

/* ft_d_handler.c */
void	key_d_handler(t_game *game);

/* ft_init.c */
void	init_game(t_game *game);
void	init_item_cnt(t_game *game);
void	init_window(t_game *game);

#endif
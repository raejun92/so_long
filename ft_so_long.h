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
void	key_w_handler(char **map);
void	draw_map(t_game *game);

/* ft_utils.c */
void	error_msg(void);
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s1);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);


/* ft_utils2.c */
char	*ft_strjoin(char const *s1, char const *s2);
char	**ft_split(char const *s, char c);

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
int	click_x(t_game *game);
void	process_event(t_game *game);

#endif
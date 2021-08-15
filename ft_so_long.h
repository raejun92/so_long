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

// typedef struct s_map {
// 	char	**map;
// }t_map;

typedef struct s_game {
	void	*mlx;
	void	*win;
	void	*img;
	int		cnt;
	int		img_width;
	int 	img_height;
	// t_map	map;
	char	**map;
}t_game;

/* ft_so_long.c */

/* ft_utils.c */
void	error_msg(void);
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s1);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);


/* ft_utils2.c */
char	*ft_strjoin(char const *s1, char const *s2);
char	**ft_split(char const *s, char c);

#endif
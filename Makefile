all:
	gcc -L./mlx -lmlx -framework OpenGL -framework AppKit ft_so_long.c ft_utils.c ft_utils2.c ft_check_map.c ft_parse.c ft_draw.c ft_key_event.c

all:
	gcc -L./mlx -lmlx -framework OpenGL -framework AppKit ft_so_long.c ft_utils.c

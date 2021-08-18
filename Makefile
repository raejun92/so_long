NAME = so_long

OBJS = $(FILES:.c=.o)
CC = gcc
CFLAGS = -Wall -Wextra -Werror
MLX = -L./mlx -lmlx -framework OpenGL -framework AppKit
FILES = ft_so_long.c \
		ft_utils.c \
		ft_utils2.c \
		ft_check_map.c \
		ft_parse.c \
		ft_draw.c \
		ft_key_event.c \
		ft_w_handler.c \
		ft_s_handler.c \
		ft_a_handler.c \
		ft_d_handler.c \
		ft_init.c

.PHONY : all clean fclean re

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) ${MLX} $(OBJS) -o $(NAME)

clean :
	rm -f *.o

fclean : clean
	rm -f $(NAME)

re : fclean all
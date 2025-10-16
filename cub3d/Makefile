CUR_DIR = $(shell pwd)

NAME = so_long
CC = cc

MLX_FLAGS = -Lmlx -lmlx -L/usr/lib/X11 -lXext -lX11
RM = rm -f
CFLAGS += -Wall -Wextra -Werror
LIBFT_DIR = $(CUR_DIR)/Libft


SRCS = \
	src/main.c \
	src/check_map_extension.c \
	src/init_graphics.c \
	src/fill_coins_position.c \
	src/map_str_to_matrix.c \
	src/check_border.c \
	src/dfs.c \
	src/clean_matrix.c \
	src/check_accessability.c \
	src/init_data.c \
	src/ft_error.c \
	src/move_player.c \
	src/key_press.c \
	src/display_game.c \
	src/close_game.c \
	src/s_free.c \
	src/gnl/get_next_line.c\
	src/gnl/get_next_line_utils.c

MY_HEADERS = $(CUR_DIR)/includes/so_long.h

OBJS = $(SRCS:.c=.o)

all:  $(NAME)

$(NAME): $(LIBFT_DIR)/libft.a $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(MLX_FLAGS) -L$(LIBFT_DIR) -lft -o $(NAME)

$(LIBFT_DIR)/libft.a:
	$(MAKE) -C $(LIBFT_DIR)
	
%.o: %.c ../$(MY_HEADERS)
	$(CC) $(CFLAGS) -I/usr/include -Imlx_linux -O3 -c $< -o $@

clean: 	
	$(MAKE) -C $(LIBFT_DIR) clean
	$(RM) $(OBJS)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(RM) $(NAME)

re:	fclean all
		$(MAKE) -C $(LIBFT_DIR)
		$(RM) $(OBJS)

.PHONY: all clean fclean re
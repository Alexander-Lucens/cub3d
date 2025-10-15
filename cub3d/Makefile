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

SRCS_BONUS = \
	bonus/main.c \
	bonus/show_info.c \
	bonus/check_map_extension.c \
	bonus/init_graphics.c \
	bonus/init_img.c \
	bonus/fill_coins_position.c \
	bonus/map_str_to_matrix.c \
	bonus/check_border.c \
	bonus/dfs.c \
	bonus/clean_matrix.c \
	bonus/check_accessability.c \
	bonus/init_data.c \
	bonus/ft_error.c \
	bonus/move_player.c \
	bonus/key_press.c \
	bonus/display_game.c \
	bonus/close_game.c \
	bonus/s_free.c \
	bonus/gnl/get_next_line.c\
	bonus/gnl/get_next_line_utils.c

MY_HEADERS = $(CUR_DIR)/includes/so_long.h

OBJS = $(SRCS:.c=.o)

OBJS_BONUS = $(SRCS_BONUS:.c=.o)

all:  $(NAME)

$(NAME): $(LIBFT_DIR)/libft.a $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(MLX_FLAGS) -L$(LIBFT_DIR) -lft -o $(NAME)

bonus: $(LIBFT_DIR)/libft.a $(OBJS_BONUS)
	$(CC) $(CFLAGS) $(OBJS_BONUS) $(MLX_FLAGS) -L$(LIBFT_DIR) -lft -o $(NAME)

$(LIBFT_DIR)/libft.a:
	$(MAKE) -C $(LIBFT_DIR)
	
%.o: %.c ../$(MY_HEADERS)
	$(CC) $(CFLAGS) -I/usr/include -Imlx_linux -O3 -c $< -o $@

clean: 	
	$(MAKE) -C $(LIBFT_DIR) clean
	$(RM) $(OBJS)
	$(RM) $(OBJS_BONUS)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(RM) $(NAME)

re:	fclean all
		$(MAKE) -C $(LIBFT_DIR) clean
		$(RM) $(OBJS)
		$(RM) $(OBJS_BONUS)

.PHONY: all clean fclean re bonus
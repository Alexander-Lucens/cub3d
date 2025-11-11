# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akuzmin <akuzmin@student.42berlin.de>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/10 10:46:56 by akuzmin           #+#    #+#              #
#    Updated: 2025/11/10 23:58:19 by akuzmin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:=	cub3d

# **************************************************************************** #

SRC_DIR		:=	src/

SUB_DIR		:=	core/ parser/ render/ input/ init/ utils/ ../tests/

OBJ_DIR		:=	objs/

INC_DIR		:=	includes/

# **************************************************************************** #

SRCS		:=	main.c statusPrints.c \
				parser.c parser_utils.c \
				check_map_grid.c check_border.c check_map.c \
				check_textures.c dfs.c \
				cub_free.c map_to_matrix.c ft_error.c \
				exit_game.c cleanup_graphics.c \
				init_data.c init_graphics.c init_rgb.c \
				key_press.c move_player.c update.c \
				close_game.c display_game.c draw_utils.c draw_wall.c init_render_data.c \
				t_pos.c time_utils.c \
				tests_init.c test_data_free.c main_test.c map0.c map1.c map2.c \
				tests_maps.c tests.c tests_utils.c validator.c

OBJS		:=	$(patsubst %.c,$(OBJ_DIR)%.o,$(SRCS))

# **************************************************************************** #

LIBFT_NAME	:=	libft.a

LIBFT_DIR	:=	./Libft

LIBFT		:=	$(LIBFT_DIR)/$(LIBFT_NAME)

# **************************************************************************** #

CC			:=	cc

CFLAGS		:=	-Wall -Wextra -Werror -g

# g: CFLAGS	+=	-g

CPPFLAGS	:=	-I$(INC_DIR) -I$(LIBFT_DIR)/include

LIBFLAGS	:=	-L$(LIBFT_DIR) -l:$(LIBFT_NAME) \
				-L/usr/local/lib -lmlx -lXext -lX11 -lm -lz

RM			:=	rm -rf

# * VPATH ******************************************************************* #

vpath %.c $(SRC_DIR) $(patsubst %, $(SRC_DIR)%, $(SUB_DIR))

# **************************************************************************** #

all: $(NAME)

g: fclean $(NAME)

$(NAME): $(LIBFT) $(OBJ_DIR) $(OBJS)
	@$(CC) $(CFLAGS) $(CPPFLAGS) $(OBJS) $(LIBFLAGS) -o $(NAME)
	@echo "Creating program $(NAME)."

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR) CFLAGS="$(CFLAGS)"

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)
	@echo "Creating $(OBJ_DIR) directory."

$(OBJ_DIR)%.o: %.c
	@$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@
	@echo "Compiling $@."

re: fclean all

clean:
	@$(RM) $(OBJ_DIR)
	@echo "Deleting object files for program $(NAME)."
	@$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	@$(RM) $(NAME)
	@echo "Deleting program $(NAME)."
	@$(MAKE) -C $(LIBFT_DIR) fclean

.PHONY: all re clean fclean g

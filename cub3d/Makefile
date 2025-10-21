# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akuzmin <akuzmin@student.42berlin.de>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/10 10:46:56 by akuzmin           #+#    #+#              #
#    Updated: 2025/10/21 03:27:56 by akuzmin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:=	so_long

# **************************************************************************** #

SRC_DIR		:=	src/

SUB_DIR		:=	core/ parser/ render/ input/

OBJ_DIR		:=	objs/

INC_DIR		:=	includes/

# **************************************************************************** #

SRCS		:=	main.c \
				ft_error.c s_free.c \
				check_map_extension.c map_str_to_matrix.c check_border.c \
				check_accessability.c dfs.c clean_matrix.c init_data.c \
				fill_coins_position.c \
				init_graphics.c display_game.c close_game.c \
				key_press.c move_player.c

OBJS		:=	$(patsubst %.c,$(OBJ_DIR)%.o,$(SRCS))

# **************************************************************************** #

LIBFT_NAME	:=	libft.a

LIBFT_DIR	:=	./Libft

LIBFT		:=	$(LIBFT_DIR)/$(LIBFT_NAME)

# **************************************************************************** #

CC			:=	cc

CFLAGS		:=	-Wall -Wextra -Werror

g: CFLAGS	+=	-g

CPPFLAGS	:=	-I$(INC_DIR) -I$(LIBFT_DIR)/include

LIBFLAGS	:=	-L$(LIBFT_DIR) -l:$(LIBFT_NAME) -L/usr/lib/X11 -lXext -lX11 -lmlx

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
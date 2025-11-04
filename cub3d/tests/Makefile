# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lkramer <lkramer@student.42berlin.de>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/10 10:46:56 by akuzmin           #+#    #+#              #
#    Updated: 2025/11/04 16:23:05 by lkramer          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        := parser_tests

# **************************************************************************** #

SRC_DIR		:=	./

SUB_DIR		:=	parsed_data/

OBJ_DIR		:=	objs/

INC_DIR		:=	includes/

# **************************************************************************** #

SRCS		:=	init.c  main.c  maps.c  tests.c  utils.c  validator.c \
				../../src/parser/parser.c \
			  	../../src/init/init_data.c \
				../../src/parser/utils.c \
				../../src/parser/check_map_grid.c \
				../../src/parser/check_border.c \
				../../src/parser/check_map.c \
				../../src/parser/check_textures.c \
				../../src/parser/dfs.c \
				../../src/core/cub_free.c \

OBJS		:=	$(patsubst %.c,$(OBJ_DIR)%.o,$(SRCS))

# **************************************************************************** #

LIBFT_NAME	:=	libft.a

LIBFT_DIR	:=	../Libft

LIBFT		:=	$(LIBFT_DIR)/$(LIBFT_NAME)

# **************************************************************************** #

CC			:=	cc

CFLAGS		:=	-Wall -Wextra -Werror -g

g: CFLAGS	+=	-g

CPPFLAGS	:=	-I$(INC_DIR) -I$(LIBFT_DIR)/include

LIBFLAGS	:=	-L$(LIBFT_DIR) -l:$(LIBFT_NAME) -L/usr/lib/X11 -lXext -lX11 -lmlx

RM			:=	rm -rf

# * VPATH ******************************************************************* #

vpath %.c $(SRC_DIR) $(patsubst %, $(SRC_DIR)%, $(SUB_DIR)) ../../src/parser/

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
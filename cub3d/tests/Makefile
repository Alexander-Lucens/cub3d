# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akuzmin <akuzmin@student.42berlin.de>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/10 10:46:56 by akuzmin           #+#    #+#              #
#    Updated: 2025/10/24 02:35:34 by akuzmin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:=	parser_tests

# **************************************************************************** #

SRC_DIR		:=	../src/
TEST_DIR	:=	.
OBJ_DIR		:=	obj/
INC_DIR		:=	../includes/
LIBFT_DIR	:=	../Libft/

# **************************************************************************** #

SUB_DIRS	:=	parser/ parsed_data/
SRCS_PARSER	:=	$(foreach dir,$(SUB_DIRS),$(wildcard $(SRC_DIR)$(dir)*.c))
SRCS_TESTS	:=	$(wildcard $(TEST_DIR)/*.c)

SRCS		:=	$(SRCS_PARSER) $(SRCS_TESTS)
BASENAMES	:=	$(notdir $(SRCS))
OBJS		:=	$(patsubst %.c,$(OBJ_DIR)%.o,$(BASENAMES))

# **************************************************************************** #

LIBFT_NAME	:=	libft.a
LIBFT		:=	$(LIBFT_DIR)/$(LIBFT_NAME)

# **************************************************************************** #

CC			:=	cc
CFLAGS		:=	-Wall -Wextra -Werror -g
CPPFLAGS	:=	-I$(INC_DIR) -I$(LIBFT_DIR)/include
LIBFLAGS	:=	-L$(LIBFT_DIR) -l:$(LIBFT_NAME)

RM			:=	rm -rf

# **************************************************************************** #

vpath %.c $(SRC_DIR) $(patsubst %,$(SRC_DIR)%,$(SUB_DIRS)) $(TEST_DIR)

# **************************************************************************** #

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ_DIR) $(OBJS)
	@$(CC) $(CFLAGS) $(CPPFLAGS) $(OBJS) $(LIBFLAGS) -o $(NAME)
	@echo "\033[1;32m[OK]\033[0m Built $(NAME) successfully."

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR) CFLAGS="$(CFLAGS)"

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)
	@echo "Creating $(OBJ_DIR) directory."

$(OBJ_DIR)%.o: %.c
	@$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@
	@echo "Compiling $@."

run: all
	@echo "\033[1;34mRunning $(NAME)...\033[0m"
	@./$(NAME)

clean:
	@$(RM) $(OBJ_DIR)
	@echo "Deleting object files for $(NAME)."
	@$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	@$(RM) $(NAME)
	@echo "Deleting executable $(NAME)."
	@$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re run
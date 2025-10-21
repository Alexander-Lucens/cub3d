# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akuzmin <akuzmin@student.42berlin.de>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/10 10:46:56 by akuzmin           #+#    #+#              #
#    Updated: 2025/10/21 16:48:36 by akuzmin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= parser_tests

# **************************************************************************** #

CC			:= cc

CFLAGS		:= -Wall -Wextra -Werror -g

# **************************************************************************** #

INC_DIR		:= ../includes

LIBFT_DIR	:= ../Libft

OBJDIR		:= obj/

LIBFLAGS	:= -L$(LIBFT_DIR) -l:libft.a

# **************************************************************************** #

SRCS_PARSER	:= ../src/parser/check_map_extension.c \
			   ../src/parser/map_str_to_matrix.c \
			   ../src/parser/check_border.c \
			   ../src/parser/check_accessability.c \
			   ../src/parser/dfs.c \
			   ../src/parser/clean_matrix.c \
			   ../src/parser/init_data.c \
			   ../src/parser/fill_coins_position.c

SRCS_TESTS	:= moks_data.c test_cases.c test_parser.c test_main.c

SRCS		:= $(SRCS_PARSER) $(SRCS_TESTS)

# **************************************************************************** #

BASENAMES	:= $(notdir $(SRCS))

OBJS := $(patsubst %.c,$(OBJDIR)/%.o,$(BASENAMES))

# **************************************************************************** #

.PHONY: all clean run

all: $(NAME)

$(NAME): | $(OBJDIR)
	@$(MAKE) -C $(LIBFT_DIR)
	@echo "Compiling parser sources and tests..."
	@for src in $(SRCS); do \
	  obj=$(OBJDIR)/$$(basename $$src .c).o; \
	  echo "  -> $$src"; \
	  $(CC) $(CFLAGS) -I$(INC_DIR) -I$(LIBFT_DIR)/include -c $$src -o $$obj || exit 1; \
	done
	@echo "Linking $(NAME)..."
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFLAGS) -o $(NAME)
	@echo "Built $(NAME)."

$(OBJDIR):
	@mkdir -p $(OBJDIR)

clean:
	@rm -rf $(OBJDIR) $(NAME)
	@echo "Cleaned tests build."

run: $(NAME)
	@./$(NAME)

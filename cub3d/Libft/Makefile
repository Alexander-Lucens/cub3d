# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akuzmin <akuzmin@student.42berlin.de>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/21 02:19:21 by akuzmin           #+#    #+#              #
#    Updated: 2025/10/21 02:30:46 by akuzmin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:=	libft.a

# **************************************************************************** #

SRC_DIR		:=	src/

SUB_DIR		:=	ctype/ io/ list/ mem/ misc/ printf/ str/

OBJ_DIR		:=	objs/

INC_DIR		:=	include/

# **************************************************************************** #

SRCS		:=	ft_isalpha.c ft_isdigit.c \
				ft_print_pointer.c ft_putbase.c ft_putchar_fd.c ft_putchar.c \
				ft_putendl_fd.c ft_putnbr_fd.c ft_putnbr.c ft_putstr_fd.c ft_putstr.c \
				get_next_line_utils.c get_next_line.c \
				ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c ft_lstdelone.c \
				ft_lstiter.c ft_lstlast.c ft_lstmap.c ft_lstnew.c ft_lstsize.c \
				ft_bzero.c ft_calloc.c ft_memchr.c ft_memcmp.c ft_memcpy.c \
				ft_memmove.c ft_memset.c \
				ft_atoi.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_itoa.c ft_split.c \
				ft_printf.c \
				ft_strchr.c ft_strdup.c ft_striteri.c ft_strjoin.c ft_strlcat.c \
				ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c \
				ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c

OBJS		:=	$(patsubst %.c,$(OBJ_DIR)%.o,$(SRCS))

# **************************************************************************** #

CC			:=	cc

CFLAGS		:=	-Wall -Wextra -Werror -I $(INC_DIR)

AR			:=	ar rcs

RM			:=	rm -rf

# * VPATH ******************************************************************* #

vpath %.c $(patsubst %, $(SRC_DIR)%, $(SUB_DIR))

# **************************************************************************** #

all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJS)
	@$(AR) $@ $(OBJS)
	@echo "Creating library $(NAME)."

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)
	@echo "Creating $(OBJ_DIR) directory."

$(OBJ_DIR)%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "Compiling $@."

re: fclean all

clean:
	@$(RM) $(OBJ_DIR)
	@echo "Deleting object files for library $(NAME)."

fclean: clean
	@$(RM) $(NAME)
	@echo "Deleting library $(NAME)."

.PHONY: all re clean fclean
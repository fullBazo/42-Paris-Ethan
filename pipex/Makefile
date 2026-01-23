# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ehuet <ehuet@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/20 12:43:14 by ehuet             #+#    #+#              #
#    Updated: 2026/01/20 14:51:27 by ehuet            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# =======================
# Variables
# =======================

NAME        = pipex

CC          = cc
CFLAGS      = -Wall -Wextra -Werror -g3

RM          = rm -f

# =======================
# Directories
# =======================

LIBFT_DIR   = libft
LIBFT       = $(LIBFT_DIR)/libft.a

INCLUDES    = -I includes -I $(LIBFT_DIR)/includes

# =======================
# Sources
# =======================

SRCS =  src/main.c \
		src/path.c \

OBJS = $(SRCS:.c=.o)

# =======================
# Rules
# =======================

all: $(LIBFT) $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# =======================
# Libft
# =======================

$(LIBFT):
	make -C $(LIBFT_DIR)

# =======================
# Clean
# =======================

clean:
	make clean -C $(LIBFT_DIR)
	$(RM) $(OBJS)

fclean: clean
	make fclean -C $(LIBFT_DIR)
	$(RM) $(NAME)

re: fclean all

# =======================
# Phony
# ==========

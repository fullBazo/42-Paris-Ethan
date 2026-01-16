# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ehuet <ehuet@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/14 15:42:35 by ehuet             #+#    #+#              #
#    Updated: 2026/01/15 18:03:33 by ehuet            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ---------- Variables ----------
NAME = push_swap
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
SRC_DIR = src
SRC = $(shell find $(SRC_DIR) -type f -name "*.c")
OBJ = $(SRC:.c=.o)

# ---------- Règles par défaut ----------
all: $(LIBFT) $(NAME)

# ---------- Compilation de libft ----------
$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

# ---------- Compilation de push_swap ----------
$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) -L$(LIBFT_DIR) -lft

# ---------- Compilation des objets ----------
%.o: %.c
	$(CC) $(CFLAGS) -I./$(SRC_DIR) -I$(LIBFT_DIR) -c $< -o $@

# ---------- Nettoyage ----------
clean:
	$(RM) $(OBJ)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re

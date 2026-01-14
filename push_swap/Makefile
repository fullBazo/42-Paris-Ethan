# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ehuet <ehuet@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/14 15:42:35 by ehuet             #+#    #+#              #
#    Updated: 2026/01/14 15:47:50 by ehuet            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Nom de l’exécutable
NAME = push_swap

# Compilateur et flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror
INC = -Iincludes -Ilibft

# Répertoires
SRC_DIR = src
OBJ_DIR = obj
LIBFT_DIR = libft

# Fichiers sources
SRCS = $(shell find $(SRC_DIR) -name "*.c")
OBJS = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRCS))

# Libft
LIBFT = $(LIBFT_DIR)/libft.a

#---------------------------------------------------

# Cible par défaut
all: $(LIBFT) $(NAME)

# Compilation de l’exécutable
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

# Compilation des .c en .o
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

# Créer le dossier obj si inexistant
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

# Compilation de libft
$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

# Nettoyage des objets
clean:
	rm -rf $(OBJ_DIR)
	@$(MAKE) -C $(LIBFT_DIR) clean

# Nettoyage complet
fclean: clean
	rm -f $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean

# Recompilation complète
re: fclean all

# Règles phony
.PHONY: all clean fclean re

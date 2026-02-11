# **************************************************************************** #
#																			   #
#														  :::	   ::::::::    #
#	 Makefile											:+:		 :+:	:+:    #
#													  +:+ +:+		  +:+	   #
#	 By: ehuet <ehuet@student.42.fr>				+#+  +:+	   +#+		   #
#												  +#+#+#+#+#+	+#+			   #
#	 Created: 2026/02/06 16:39:22 by ehuet			   #+#	  #+#			   #
#	 Updated: 2026/02/06 16:39:22 by ehuet			  ###	########.fr		   #
#																			   #
# **************************************************************************** #

# Program name
NAME		= fractol

# Compiler and flags
CC			= cc
CFLAGS		= -Wall -Wextra -Werror
INCLUDES	= -I. -Ilibft -Iminilibx-linux
MLXFLAGS	= -Lminilibx-linux -lmlx -lXext -lX11 -lm

# Directories
SRC_DIR		= src
LIBFT_DIR	= libft
MLX_DIR		= minilibx-linux

# Libraries
LIBFT		= $(LIBFT_DIR)/libft.a
MLX			= $(MLX_DIR)/libmlx.a

# Source files
SRC			= $(SRC_DIR)/main.c \
			  $(SRC_DIR)/mandatory.c \
			  $(SRC_DIR)/utils.c \
			  $(SRC_DIR)/julia.c \
			  $(SRC_DIR)/moves.c \
			  $(SRC_DIR)/mandelbrot.c \

# Object files
OBJ			= $(SRC:.c=.o)

# Colors for output
GREEN		= \033[0;32m
RED			= \033[0;31m
RESET		= \033[0m

# Rules
all: $(NAME)

$(NAME): $(LIBFT) $(MLX) $(OBJ)
	@echo "$(GREEN)Linking $(NAME)...$(RESET)"
	@$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(MLXFLAGS) -o $(NAME)
	@echo "$(GREEN)$(NAME) created successfully!$(RESET)"

%.o: %.c
	@echo "Compiling $<..."
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(LIBFT):
	@echo "$(GREEN)Building libft...$(RESET)"
	@make -C $(LIBFT_DIR) --no-print-directory

$(MLX):
	@echo "$(GREEN)Building minilibx...$(RESET)"
	@make -C $(MLX_DIR) --no-print-directory

clean:
	@echo "$(RED)Cleaning object files...$(RESET)"
	@rm -f $(OBJ)
	@make -C $(LIBFT_DIR) clean --no-print-directory
	@make -C $(MLX_DIR) clean --no-print-directory

fclean: clean
	@echo "$(RED)Removing $(NAME)...$(RESET)"
	@rm -f $(NAME)
	@make -C $(LIBFT_DIR) fclean --no-print-directory

re: fclean all

.PHONY: all clean fclean re

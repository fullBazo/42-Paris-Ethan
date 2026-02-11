# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ehuet <ehuet@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/20 12:43:14 by ehuet             #+#    #+#              #
#    Updated: 2026/01/27 14:21:24 by ehuet            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        = pipex
CC          = cc
CFLAGS      = -Wall -Wextra -Werror -g3
RM          = rm -f

LIBFT_DIR   = libft
LIBFT       = $(LIBFT_DIR)/libft.a
INCLUDES    = -I includes -I $(LIBFT_DIR)/includes

SRCS        = src/main.c src/path.c src/utils.c src/pipe.c
OBJS        = $(SRCS:.c=.o)

GREEN       = \033[1;32m
CYAN        = \033[1;36m
YELLOW      = \033[1;33m
RESET       = \033[0m

all: $(LIBFT) $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)
	@echo "$(GREEN)✓ $(NAME) compiled successfully!$(RESET)"

%.o: %.c
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
	@echo "$(CYAN)[█] $(RESET)Compiled: $(YELLOW)$<$(RESET)"

$(LIBFT):
	@echo "$(CYAN)Building libft...$(RESET)"
	@make -C $(LIBFT_DIR) --silent

clean:
	@make clean -C $(LIBFT_DIR) --silent
	@$(RM) $(OBJS)
	@echo "$(YELLOW)✓ Objects cleaned$(RESET)"

fclean: clean
	@make fclean -C $(LIBFT_DIR) --silent
	@$(RM) $(NAME)
	@echo "$(YELLOW)✓ $(NAME) removed$(RESET)"

re: fclean all

.PHONY: all clean fclean re

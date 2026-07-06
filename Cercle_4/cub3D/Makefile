# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rdupoix <rdupoix@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/06/19 14:32:20 by ehuet             #+#    #+#              #
#    Updated: 2026/07/01 08:26:20 by ehuet            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= cub3D

CC		= cc
CFLAGS		= -Wall -Wextra -Werror -g3
INCLUDES	= -I. -I includes -I libft -I minilibx
MAP        ?= map/good_map.cub


SRCS		= srcs/main.c \
		  srcs/cleaning/clean_parsing.c \
		  srcs/cleaning/clean_mlx.c \
		  srcs/parsing/collect_map.c \
		  srcs/parsing/flood_fill.c \
		  srcs/parsing/parse_elements.c \
		  srcs/parsing/parse_scene.c \
		  srcs/parsing/parse_utils.c \
		  srcs/parsing/read_scene.c \
		  srcs/parsing/validate_map.c \
		  srcs/game/init/init_game.c \
		  srcs/game/moovement/moove.c \
		  srcs/game/moovement/moove_utils.c \
		  srcs/game/moovement/collision.c \
		  srcs/game/moovement/spawn.c \
		  srcs/game/raycasting/draw_element.c \
		  srcs/game/raycasting/raycasting.c \
		  srcs/game/raycasting/utils.c

OBJS		= $(SRCS:srcs/%.c=objs/%.o)

LIBFT		= libft/libft.a
MLX		= 	minilibx/libmlx_Linux.a
LIBS		= -L libft -lft -L minilibx -lmlx_Linux -lX11 -lXext -lm
HEADERS  =  includes/cub3d.h \
			includes/struct.h \
			srcs/parsing/parsing.h \
			srcs/cleaning/cleaning.h


all: $(NAME)

$(NAME): $(LIBFT) $(MLX) $(OBJS)                                                                                             
	$(CC) $(CFLAGS) $(OBJS) $(LIBS) -o $(NAME)

objs/%.o: srcs/%.c $(HEADERS)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(LIBFT):
	$(MAKE) -C libft

$(MLX):
	$(MAKE) -C minilibx

run: re
	./$(NAME) $(MAP)
	
debug: re
	gdb -tui -x .debug.gdb --args $(NAME) $(MAP)
	
norm:
	@norminette $$(find . -name '*.c' -o -name '*.h' | grep -v minilibx) || true

vg: re
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --track-fds=yes ./$(NAME) $(MAP)


clean:
	$(MAKE) -C libft clean
	$(MAKE) -C minilibx clean
	rm -rf objs

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

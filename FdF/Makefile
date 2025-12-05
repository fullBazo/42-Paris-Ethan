NAME = fdf

CC = gcc
CFLAGS = -Wall -Wextra -Werror -I includes -I libft -I minilibx-linux

SRC_DIR = srcs
OBJ_DIR = objs

SRC = $(wildcard $(SRC_DIR)/*.c)
OBJ = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

LIBFT = libft/libft.a
MLX = minilibx-linux/libmlx.a

$(NAME): $(LIBFT) $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFT) $(MLX) -lXext -lX11 -lm -lbsd

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	make -C libft

all: $(NAME)

clean:
	rm -rf $(OBJ_DIR)
	make -C libft clean

fclean: clean
	rm -f $(NAME)
	make -C libft fclean

re: fclean all

.PHONY: all clean fclean re
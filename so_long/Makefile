# ======================
#        PROGRAM
# ======================

NAME		= so_long

# ======================
#        COMPILER
# ======================

CC			= cc
CFLAGS		= -Wall -Wextra -Werror -g

# ======================
#        DIRECTORIES
# ======================

SRC_DIR		= src
OBJ_DIR		= obj
LIBFT_DIR	= libft
MLX_DIR		= minilibx-linux

# ======================
#        SOURCES
# ======================

SRC_FILES	=	main.c \
				parsing.c \
				read_map.c \
				flood_fill.c \
				flood_fill_utils.c \
				so_long_free.c

SRCS		= $(addprefix $(SRC_DIR)/, $(SRC_FILES)) mlx/window.c

# ======================
#        OBJECTS
# ======================

OBJS		= $(addprefix $(OBJ_DIR)/, $(SRC_FILES:.c=.o)) \
			  $(OBJ_DIR)/window.o

# ======================
#        LIBRARIES
# ======================

LIBFT		= $(LIBFT_DIR)/libft.a
MLX			= $(MLX_DIR)/libmlx.a

LIBS		= -L$(LIBFT_DIR) -lft \
			  -L$(MLX_DIR) -lmlx \
			  -lXext -lX11 -lm

INCLUDES	= -I. -I$(LIBFT_DIR) -I$(MLX_DIR)

# ======================
#        RULES
# ======================

all: $(NAME)

$(NAME): $(LIBFT) $(MLX) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBS) -o $(NAME)

# ======================
#        OBJECT RULES
# ======================

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c so_long.h
	mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJ_DIR)/window.o: mlx/window.c so_long.h
	mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# ======================
#        LIBFT
# ======================

$(LIBFT):
	make -C $(LIBFT_DIR)

# ======================
#        MLX
# ======================

$(MLX):
	make -C $(MLX_DIR)

# ======================
#        CLEAN
# ======================

clean:
	rm -rf $(OBJ_DIR)
	make -C $(LIBFT_DIR) clean
	make -C $(MLX_DIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all

# ======================
#        PHONY
# ======================

.PHONY: all clean fclean re

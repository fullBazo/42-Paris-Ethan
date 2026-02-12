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
CHECKER = checker_linux
ARG10 = 1 4 10 9 8 7 6 11 2 24
ARG = 1 2 3 4 5
ARG5 = 5 3 2 1 4

TESTER = tester
COMPLEXITY = complex_tester
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



$(CHECKER):
	wget https://cdn.intra.42.fr/document/document/39756/checker_linux -O $(CHECKER)
	chmod +x $(CHECKER)

run: $(NAME) $(CHECKER)
	 ./$(NAME) $(ARG)
	 ./$(NAME) $(ARG) | wc -l
	 ./$(NAME) $(ARG) | ./$(CHECKER) $(ARG)

run5: $(NAME) $(CHECKER)
	 ./$(NAME) $(ARG5)
	 ./$(NAME) $(ARG5) | wc -l
	 ./$(NAME) $(ARG5) | ./$(CHECKER) $(ARG5)

run3: $(NAME) $(CHECKER)
	$(MAKE) ARG="1 2 3" run
	$(MAKE) ARG="1 3 2" run
	$(MAKE) ARG="2 1 3" run
	$(MAKE) ARG="2 3 1" run
	$(MAKE) ARG="3 2 1" run
	$(MAKE) ARG="3 1 2" run

	 
run10: $(NAME) $(CHECKER)
	 ./$(NAME) $(ARG10)
	 ./$(NAME) $(ARG10) | wc -l
	 ./$(NAME) $(ARG10) | ./$(CHECKER) $(ARG10)

$(COMPLEXITY):
	git clone https://github.com/SimonCROS/push_swap_tester $(COMPLEXITY)

$(TESTER):
	git clone https://github.com/gemartin99/Push-Swap-Tester $(TESTER)

test: $(NAME) $(TESTER) $(CHECKER)
	chmod +x ./$(TESTER)/push_swap_test_linux.sh
	./$(TESTER)/push_swap_test_linux.sh

run100: $(NAME) $(COMPLEXITY)
	make -C ./$(COMPLEXITY)
	./$(COMPLEXITY)/complexity 100 100 1100

run500: $(NAME) $(COMPLEXITY)
	make -C ./$(COMPLEXITY)
	./$(COMPLEXITY)/complexity 500 100 8500

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ehuet <ehuet@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/28 11:49:54 by ehuet             #+#    #+#              #
#    Updated: 2026/03/31 10:38:41 by ehuet            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        = minishell

#========================================================
# DIRECTORIES
#========================================================
SRC_DIR     = srcs
OBJ_DIR     = objs
LIBFT_DIR   = libft

#========================================================
# SOURCES
#========================================================
SRCS =  $(SRC_DIR)/main.c \
        $(wildcard $(SRC_DIR)/parsing/*.c) \
        $(wildcard $(SRC_DIR)/signals/*.c) \
        $(wildcard $(SRC_DIR)/free/*.c) \
        $(wildcard $(SRC_DIR)/exec/main_exec/*.c) \
        $(wildcard $(SRC_DIR)/exec/builtins/*.c) \
        $(wildcard $(SRC_DIR)/exec/builtins/export/*.c) \
        $(wildcard $(SRC_DIR)/exec/heredocs/*.c)

OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

LIBFT_SRCS = $(wildcard $(LIBFT_DIR)/*.c)
LIBFT_OBJS = $(LIBFT_SRCS:.c=.o)

#========================================================
# HEADERS
#========================================================
HEADERS =   includes/minishell.h \
			includes/struct.h	\
            $(SRC_DIR)/parsing/parsing.h \
            $(SRC_DIR)/signals/signals.h \
            $(SRC_DIR)/exec/exec.h \
            $(SRC_DIR)/free/free.h

#========================================================
# COMPILATION
#========================================================
CC      = cc
CFLAGS  = -Wall -Wextra -Werror -g -I. -Iincludes
LDFLAGS = -lreadline
LIBFT   = $(LIBFT_DIR)/libft.a

#========================================================
# COLORS
#========================================================
GREEN   = \033[1;32m
CYAN    = \033[1;36m
RED     = \033[1;31m
YELLOW  = \033[1;33m
RESET   = \033[0m
BOLD    = \033[1m
CLEAR   = \033[2K\r

#========================================================
# PROGRESS
#========================================================
TOTAL   = $(words $(LIBFT_SRCS) $(SRCS))
BAR_LEN = 30
COUNTER = .build_count

define show_progress
	@CNT=$$(($$(cat $(COUNTER)) + 1)); \
	printf "$$CNT" > $(COUNTER); \
	PCT=$$((CNT * 100 / $(TOTAL))); \
	FILLED=$$((CNT * $(BAR_LEN) / $(TOTAL))); \
	EMPTY=$$(($(BAR_LEN) - FILLED)); \
	printf "$(CLEAR)$(CYAN)  [$(RESET)"; \
	for i in $$(seq 1 $$FILLED); do printf "$(GREEN)█$(RESET)"; done; \
	for i in $$(seq 1 $$EMPTY); do printf "$(RED)░$(RESET)"; done; \
	printf "$(CYAN)]$(RESET) $(BOLD)%3d%%$(RESET)  $(CYAN)%s$(RESET)" $$PCT $(notdir $<)
endef

#========================================================
# RULES
#========================================================
all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	@printf "\n"
	@printf "$(CYAN)  Linking...$(RESET)\n"
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(LDFLAGS) -o $(NAME)
	@printf "$(GREEN)  ✓ $(BOLD)$(NAME)$(RESET)$(GREEN) ready$(RESET)\n"
	@rm -f $(COUNTER)

$(LIBFT): $(LIBFT_OBJS)
	@ar rcs $(LIBFT) $(LIBFT_OBJS)

$(LIBFT_DIR)/%.o: $(LIBFT_DIR)/%.c
	@if [ ! -f $(COUNTER) ]; then printf "0" > $(COUNTER); fi
	@$(CC) $(CFLAGS) -c $< -o $@
	$(show_progress)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(HEADERS)
	@mkdir -p $(@D)
	@if [ ! -f $(COUNTER) ]; then printf "0" > $(COUNTER); fi
	@$(CC) $(CFLAGS) -c $< -o $@
	$(show_progress)

#========================================================
# CLEAN
#========================================================
clean:
	@rm -rf $(OBJ_DIR)
	@rm -f $(LIBFT_OBJS)
	@rm -f $(COUNTER)
	@printf "$(YELLOW)  ✓ objects cleaned$(RESET)\n"

fclean: clean
	@rm -f $(NAME)
	@rm -f $(LIBFT)
	@printf "$(RED)  ✓ $(NAME) removed$(RESET)\n"

re: fclean all

.PHONY: all clean fclean re
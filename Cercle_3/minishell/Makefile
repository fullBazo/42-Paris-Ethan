# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ehuet <ehuet@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/28 11:49:54 by ehuet             #+#    #+#              #
#    Updated: 2026/03/06 13:23:30 by ehuet            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= minishell

CC		= cc
CFLAGS	= -Wall -Wextra -Werror
LIBS	= -lreadline

SRCS	=	srcs/main.c \
			srcs/parsing/parsing.c \
			srcs/parsing/utils.c

OBJS	= $(SRCS:.c=.o)

LIBFT	= libft/libft.a

all: $(NAME)

$(LIBFT):
	$(MAKE) -C libft

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(LIBS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -I. -c $< -o $@

clean:
	$(MAKE) -C libft clean
	rm -f $(OBJS)

fclean: clean
	$(MAKE) -C libft fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
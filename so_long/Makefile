# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ehuet <ehuet@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/12 12:27:33 by ehuet             #+#    #+#              #
#    Updated: 2025/12/18 14:07:39 by ehuet            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = so_long

# -------------------
# Fichiers sources du projet
# -------------------
SRC = src/main.c src/parsing.c

# -------------------
# Tous les fichiers libft nécessaires
# -------------------
LIBFT = libft/ft_atoi.c libft/ft_bzero.c libft/ft_calloc.c libft/ft_isalnum.c \
        libft/ft_isalpha.c libft/ft_isascii.c libft/ft_isdigit.c libft/ft_isprint.c \
        libft/ft_itoa.c libft/ft_memchr.c libft/ft_memcmp.c libft/ft_memcpy.c \
        libft/ft_memmove.c libft/ft_memset.c libft/ft_printf.c libft/ft_printf_utils.c \
        libft/ft_printf_utils2.c libft/ft_putchar_fd.c libft/ft_putendl_fd.c \
        libft/ft_putnbr_fd.c libft/ft_putstr_fd.c libft/ft_split.c libft/ft_strchr.c \
        libft/ft_strdup.c libft/ft_striteri.c libft/ft_strjoin.c libft/ft_strlcat.c \
        libft/ft_strlcpy.c libft/ft_strlen.c libft/ft_strmapi.c libft/ft_strncmp.c \
        libft/ft_strnstr.c libft/ft_strrchr.c libft/ft_strtrim.c libft/ft_substr.c \
        libft/ft_tolower.c libft/ft_toupper.c libft/get_next_line.c

OBJ = src/main.o src/parsing.o src/read_map.o src/so_long_free.o src/flood_fill_utils.o \
      libft/ft_atoi.o libft/ft_bzero.o libft/ft_calloc.o libft/ft_isalnum.o \
      libft/ft_isalpha.o libft/ft_isascii.o libft/ft_isdigit.o libft/ft_isprint.o \
      libft/ft_itoa.o libft/ft_memchr.o libft/ft_memcmp.o libft/ft_memcpy.o \
      libft/ft_memmove.o libft/ft_memset.o libft/ft_printf.o libft/ft_printf_utils.o \
      libft/ft_printf_utils2.o libft/ft_putchar_fd.o libft/ft_putendl_fd.o \
      libft/ft_putnbr_fd.o libft/ft_putstr_fd.o libft/ft_split.o libft/ft_strchr.o \
      libft/ft_strdup.o libft/ft_striteri.o libft/ft_strjoin.o libft/ft_strlcat.o \
      libft/ft_strlcpy.o libft/ft_strlen.o libft/ft_strmapi.o libft/ft_strncmp.o \
      libft/ft_strnstr.o libft/ft_strrchr.o libft/ft_strtrim.o libft/ft_substr.o \
      libft/ft_tolower.o libft/ft_toupper.o libft/get_next_line.o

INCLUDES = -I includes -I libft

# -------------------
# Règles
# -------------------
all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re


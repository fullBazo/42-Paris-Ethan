NAME = libftprintf.a

SRCS =  ft_printf.c \
		#ft_printf_utils.c \
		ft_printf_utils2.c \
		ft_printf_utils3.c \
		ft_printf_utils4.c \
		ft_printf_utils5.c \
		ft_printf_utils6.c \

OBJS = $(SRCS:.c=.o)

CC = gcc

CFLAGS = -Wall -Wextra -Werror

AR = ar rcs

RM = rm -f

INCLUDES = -I /home/ehuet/42/ethan_github_42/libft

LIBFT = /home/ehuet/42/ethan_github_42/libft/libft.a

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(AR) $(NAME) $(OBJS)

$(LIBFT):
	make -C /home/ehuet/42/ethan_github_42/libft	

clean:
	$(RM) $(OBJS)
	make -C /home/ehuet/42/ethan_github_42/libft clean	

fclean: clean
	$(RM) $(NAME)
	make -C /home/ehuet/42/ethan_github_42/libft fclean

re: fclean all
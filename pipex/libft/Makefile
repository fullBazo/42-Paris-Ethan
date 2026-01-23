NAME = libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

# Color codes for terminal output
GREEN  = \033[0;32m
YELLOW = \033[0;33m
RED    = \033[0;31m
RESET  = \033[0m

# Source files
SRCS = ft_atoi.c ft_bzero.c ft_isprint.c ft_memchr.c ft_memcpy.c ft_memmove.c ft_isalpha.c ft_isalnum.c\
	   ft_isascii.c ft_isdigit.c ft_memset.c ft_memcmp.c ft_strchr.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strncmp.c \
	   ft_strnstr.c ft_strrchr.c ft_tolower.c ft_toupper.c ft_calloc.c ft_strdup.c \
	   ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c \
	   ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
	   get_next_line.c ft_printf.c ft_printf_utils.c ft_printf_utils2.c \
		ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c\
		ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c
		


# Object files
OBJS = $(SRCS:.c=.o)

OBJSBONUS = $(BONUS:.c=.o)
# Rules

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $@ $^
	@echo "$(GREEN)Library $(NAME) created successfully.$(RESET)"

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
	@echo "$(YELLOW)Compiled $< to $@.$(RESET)"

bonus: $(OBJSBONUS)
	ar rcs $(NAME) $(OBJSBONUS)
	@echo "$(GREEN)Bonus object files added to $(NAME).$(RESET)"

clean:
	$(RM) $(OBJS) $(OBJSBONUS)
	@echo "$(RED)Cleaned object files.$(RESET)"

fclean: clean
	$(RM) $(NAME) 
	@echo "$(RED)Removed library file.$(RESET)"

re : fclean all

.PHONY: all clean fclean re bonus test libftTester

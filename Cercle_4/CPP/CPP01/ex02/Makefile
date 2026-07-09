NAME = brain

SRCS = main.cpp 
OBJS = $(SRCS:.cpp=.o)

CC = c++
FLAGS = -Werror -Wextra -Wall --std=c++98 -g3
RM = rm -rf

all :$(NAME) 

$(NAME): $(OBJS)
	@$(CC) $(CPPFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp
	@$(CC) $(CPPFLAGS) -c $< -o $@

clean: 
	@$(RM) $(OBJS)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

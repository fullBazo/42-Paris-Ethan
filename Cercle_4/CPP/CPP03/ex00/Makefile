NAME = ClapTrap

SRCS = ClapTrap.cpp main.cpp
HEADERS = ClapTrap.hpp
OBJS = $(SRCS:.cpp=.o)

CC = c++
FLAGS = -Werror -Wextra -Wall --std=c++98
RM = rm -rf

all :$(NAME)

$(NAME) : $(OBJS) $(HEADERS)
	@$(CC) $(FLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp
	@$(CC) $(FLAGS) $(OBJS) -c $< -o $@

clean:
	@$(RM) $(OBJS)

fclean : clean
	@$(RM) $(NAME)

re : fclean all

.PHONY: all clean fclean re
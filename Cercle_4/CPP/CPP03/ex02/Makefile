NAME = FragTrap

SRCS = ClapTrap.cpp main.cpp ScavTrap.cpp FragTrap.cpp
HEADERS = ClapTrap.hpp ScavTrap.hpp FragTrap.hpp
OBJS = $(SRCS:.cpp=.o)

CC = c++
FLAGS = -Werror -Wextra -Wall --std=c++98
RM = rm -rf

all :$(NAME)

$(NAME) : $(OBJS) $(HEADERS)
	@$(CC) $(FLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp
	@$(CC) $(FLAGS) -c $< -o $@

clean:
	@$(RM) $(OBJS)

fclean : clean
	@$(RM) $(NAME)

re : fclean all

.PHONY: all clean fclean re
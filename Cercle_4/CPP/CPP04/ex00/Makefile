NAME = Animal

SRCS = Animal.cpp main.cpp Cat.cpp Dog.cpp #wrongAnimal.cpp wrongCat.cpp
HEADERS = Animal.hpp Cat.hpp Dog.hpp #wrongAnimal.hpp wrongCat.hpp
OBJS = $(SRCS:.cpp=.o)

CC = c++
FLAGS = -Werror -Wextra -Wall -g3 --std=c++98
RM = rm -rf

all :$(NAME)

$(NAME) : $(OBJS) 
	@$(CC) $(FLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp $(HEADERS)
	@$(CC) $(FLAGS) -c $< -o $@

clean:
	@$(RM) $(OBJS)

fclean : clean
	@$(RM) $(NAME)

re : fclean all

.PHONY: all clean fclean re       
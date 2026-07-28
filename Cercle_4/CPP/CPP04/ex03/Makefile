NAME = Materia

SRCS = main.cpp AMateria.cpp ICharacter.cpp IMateriaSource.cpp 
HEADERS = AMateria.hpp ICharacter.hpp IMateriaSource.hpp
OBJS = $(SRCS:.cpp=.o)

CC = c++
FLAGS = -Werror -Wextra -Wall -g3 --std=c++98
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
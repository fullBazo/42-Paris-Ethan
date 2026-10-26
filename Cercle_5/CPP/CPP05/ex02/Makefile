NAME = Bureaucrat

SRCS = main.cpp Bureaucrat.cpp
HEADERS = Bureaucrat.hpp
OBJS = $(SRCS:.cpp=.o)

CC = c++
FLAGS = -Werror -Wextra -Wall --std=c++98
RM = rm -rf

$(NAME): $(OBJS)
	@$(CC) $(FLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp $(HEADERS)
	@$(CC) $(FLAGS) -c $< -o $@

clean:
	@$(RM) $(OBJS)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

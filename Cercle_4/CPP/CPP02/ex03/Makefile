NAME = bsp

SRCS = Fixed.cpp main.cpp bsp.cpp Point.cpp
HEADERS = Fixed.hpp Point.hpp
OBJS = $(SRCS:.cpp=.o)

CC = c++
CPPFLAGS = -Werror -Wextra -Wall -g3 --std=c++98
RM = rm -rf

all :$(NAME) 

$(NAME): $(OBJS) $(HEADERS)
	@$(CC) $(CPPFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp
	@$(CC) $(CPPFLAGS) -c $< -o $@

clean: 
	@$(RM) $(OBJS)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
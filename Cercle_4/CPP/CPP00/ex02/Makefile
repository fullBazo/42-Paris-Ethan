NAME 	= phonebook

SRCS =	tests.cpp \
		PhoneBook.cpp \
		Contact.cpp 

OBJS = $(SRCS:.cpp=.o)

CC 		= g++
CPPFLAGS = -Wall -Werror -Wextra -std=c++98 -g
RM = rm -rf

all: $(NAME)

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

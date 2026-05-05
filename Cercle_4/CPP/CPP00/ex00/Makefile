NAME 	= megaphone

SRCS = megaphone.cpp \

OBJS = $(SRCS:.cpp=.o)

CC 		= c++
CPPGLAG = -Wall -Werror -Wextra -std=c++98
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
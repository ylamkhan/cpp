NAME = Bureaucrat
CC= c++ -std=c++98
CXXFLAGS = -Wextra -Wall -Werror
RM = rm -rf


SRCS = main.cpp\
		Bureaucrat.cpp

OBJS = $(SRCS:%.cpp=%.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CXXFLAGS) $(SRCS) -o $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: clean fclean re all
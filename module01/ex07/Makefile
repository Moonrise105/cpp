SRCS = main.cpp
OBJS = $(SRCS:.cpp=.o)
NAME = replace
FLAGS = -std=c++98 -Wall -Wextra -Werror
CC = clang++

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) -o $@ $^

%.o: %.cpp
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
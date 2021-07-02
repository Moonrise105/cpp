NAME = megaphone
SRCS = megaphone.cpp
CC = clang++
FLAGS = #-Wall -Wextra -Werror
OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) -o $@ $^

$(OBJS): $(SRCS)
	$(CC) $(FLAGS) -c $< -o $@

clean: 
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
.PHONY: fclean re all clean

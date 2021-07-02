NAME = prog
SOURCES = main.cpp
CC = clang++
FLAGS = -std=c++98 -Wall -Wextra -Werror
DIR_S = srcs
DIR_O = objs
SRCS = $(addprefix $(DIR_S)/, $(SOURCES))
OBJS = $(addprefix $(DIR_O)/, $(SOURCES:.cpp=.o))
HEADER = includes

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) -o $@ $^

$(DIR_O)/%.o: $(DIR_S)/%.cpp $(HEADER)/whatever.hpp
	mkdir -p $(DIR_O)
	$(CC) $(FLAGS) -I $(HEADER) -c $< -o $@

clean: 
	rm -rf $(DIR_O)

fclean: clean
	rm -f $(NAME)

re: fclean all
.PHONY: all fclean re clean

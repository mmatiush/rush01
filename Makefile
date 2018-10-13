NAME = ft_gkrellm

FLAGS = -Wall -Wextra -Werror

SRC = main.cpp TimeModule.cpp HostUserNames.cpp CPU.cpp Network.cpp \
		OSInfo.cpp RAM.cpp

OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	clang++ -lncurses $(OBJ) -o $(NAME)

%.o: %.cpp
	clang++ $(FLAGS) -o $@ -c $<

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean all re

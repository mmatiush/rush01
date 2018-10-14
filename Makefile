NAME = ft_gkrellm

FLAGS = -Wall -Wextra -Werror

SRC = main.cpp TimeModule.cpp HostUserNames.cpp CPU.cpp Network.cpp \
		OSInfo.cpp RAM.cpp SFMLDisplay.cpp

OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	clang++ -lncurses $(OBJ) -o $(NAME) -I ~/.brew/include -L ~/.brew/lib -lsfml-system -lsfml-window -lsfml-graphics -lsfml-network -lsfml-audio -rpath ~/.brew/lib -lncurses

%.o: %.cpp
	clang++ $(FLAGS) -I ~/.brew/include -o $@ -c $<

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean all re

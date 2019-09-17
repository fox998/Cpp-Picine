
SRC =	main.cpp\
		FragTrap.cpp

OBJ =	$(SRC:.cpp=.o)

NAME =	ex00

all: $(NAME)

$(NAME) : $(OBJ)
	clang++ -Werror -Wextra -Wall -o $(NAME) $(OBJ) --std=c++98

%.o:%.cpp 
	clang++ -Werror -Wextra -Wall -c $< -o $@ --std=c++98

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
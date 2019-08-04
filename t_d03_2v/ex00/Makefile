
SRC =	main.cpp\
		FragTrap.cpp

OBJ =	$(SRC:.cpp=.o)

NAME =	ex00

all: $(NAME)

$(NAME) : $(OBJ)
	clang++ -Werror -Wextra -Wall -o $(NAME) $(OBJ)

%.o:%.cpp 
	clang++ -Werror -Wextra -Wall -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

SRC =	main.cpp\
		FragTrap.cpp\
		ScavTrap.cpp\
		ClapTrap.cpp

OBJ =	$(SRC:.cpp=.o)

NAME =	ex02

all: $(NAME)

$(NAME) : $(OBJ)
	clang++ -Werror -Wextra -Wall -o $(NAME) $(OBJ)

%.o:%.cpp 
	clang++ -Werror -Wextra -Wall -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
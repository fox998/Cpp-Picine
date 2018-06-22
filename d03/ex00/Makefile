
SRC =	main.cpp\
		FragTrap.cpp

OBJ = $(SRC:.cpp=.o)

all: $(OBJ)
	clang++ -Werror -Wextra -Wall $(OBJ)

%.o : %.cpp
	clang++ -Werror -Wextra -Wall -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f a.out

re: fclean all



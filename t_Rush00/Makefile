# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: afokin <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/23 14:06:10 by afokin            #+#    #+#              #
#    Updated: 2018/06/23 14:06:12 by afokin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC =	main.cpp\
		Point.cpp\
		Object.cpp\
		Ship.cpp\
		Bullet.cpp\
		Player.cpp\
		Enemy.cpp\
		List.cpp

OBJ = $(SRC:.cpp=.o)

NAME = ft_retro

.PHONY : all clean fclean re sdlfclean

all: $(NAME)

$(NAME): $(OBJ)
	clang++ -Wall -Wextra -Werror -o $(NAME) -lncurses $(OBJ)

%.o:%.cpp
	clang++ -Wall -Wextra -Werror -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all


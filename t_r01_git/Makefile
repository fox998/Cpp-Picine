
SRC =	CPU.cpp GraphicalMode.cpp IMonitorGeneralInformation.cpp network.cpp DateTime.cpp IMonitorDisplayConsole.cpp RAM.cpp main.cpp

OBJ =	$(SRC:.cpp=.o)

INC =	IMonitorDisplay.hpp\
		IMonitorModule.hpp

NAME =	ft_gkrellm

INCLUDES	=	-I./frameworks/SDL2_ttf.framework/Versions/A/Headers \
				-I./frameworks/SDL2_image.framework/Versions/A/Headers \
				-I./frameworks/SDL2_mixer.framework/Headers \
				-I./frameworks/SDL2_net.framework/Headers \
				-F./frameworks
FRAMEWORKS	=	-F./frameworks \
				-rpath ./frameworks \
				-framework OpenGL -framework AppKit -framework OpenCl \
				-framework SDL2_ttf -framework SDL2_image \
				-framework SDL2_mixer -framework SDL2_net

SDL_FRM = -framework SDL2 -F /Library/Frameworks/ ./SDL2_ttf/SDL2_ttf
SDL_INC = -I /Library/Frameworks/SDL2.framework/Headers/ -I SDL_ttf/

all: $(NAME)

$(NAME): $(OBJ)
	clang++ -Werror -Wextra -Wall $(FRAMEWORKS) -o $(NAME) $(OBJ) -lcurses

%.o: %.cpp $(INC)
	clang++ -Werror -Wextra -Wall -c $< -o $@ $(INCLUDES)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

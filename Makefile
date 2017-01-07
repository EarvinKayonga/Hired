CC 	=	g++
CFLAGS 	= 	-W -Wall -Werror
NAME 	=	meatGrinder
RM 	=	rm -f
SRC	=	src/main.cpp
OBJ	=	$(SRC:%.cpp=%.o)

$(NAME):	$(OBJ)
		$(CC) $(OBJ) -o $(NAME)

all:		$(NAME)

clean:
		$(RM) $(OBJ)

fclean:			clean
		$(RM) $(NAME)

re:		fclean all

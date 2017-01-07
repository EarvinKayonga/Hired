CC 	=	g++
CFLAGS 	= 	-W -Wall -Werror -llept -ltesseract
NAME 	=	meatGrinder
RM 	=	rm -f
SRC	=	src/main.cpp \
			src/utils.cpp
OBJ	=	$(SRC:%.cpp=%.o)

$(NAME):	$(OBJ)
		$(CC) $(OBJ) -o $(NAME) $(CFLAGS)

all:		$(NAME)

clean:
		$(RM) $(OBJ)

fclean:			clean
		$(RM) $(NAME)

re:		fclean all

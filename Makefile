NAME	=	parser

SRC	=	src/Utils/Utils.cpp							\
		src/BracketParser/BracketParser.cpp			\
		src/BracketParser/Block/Block.cpp			\
		src/Errors/InvalidType.cpp					\
		src/Errors/InvalidValue.cpp					\
		src/Errors/UnwrapFailure.cpp				\

OBJ	=	$(SRC:.cpp=.o)

UT_SRC 	=	

MAIN	=	src/main.cpp

UT_OBJ	=	$(UT_SRC:.cpp=.o)

OBJ	=	$(SRC:.cpp=.o)

CXXFLAGS	=	 -Wextra -Wall

CXXFLAGS	+=	 -I ./include

UT_NAME	=	unit_test

CC	=	g++

LIBNAME	=	libparser.a

all	:	$(NAME)

$(NAME)	:	$(OBJ) $(MAIN)
	$(CC) $(CXXFLAGS) $(OBJ) $(MAIN) -o $(NAME) $(LDFLAGS)

lib	:	$(OBJ)
	ar rc $(LIBNAME) $(OBJ)

clean	:
		$(RM) $(OBJ)
		$(RM) $(UT_OBJ)

fclean	:	clean
		$(RM) $(NAME)
		$(RM) $(UT_NAME)
		$(RM) $(LIBNAME)

re	:	fclean all

tests_run:	CFLAGS += --coverage
tests_run:	LDFLAGS	+=	-lcriterion
tests_run	:	$(UT_OBJ)
	$(CC) $(UT_OBJ) -o $(UT_NAME) $(LDFLAGS) $(CFLAGS)
	./$(UT_NAME)

.PHONY	:	all clean fclean re

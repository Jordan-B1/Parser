SRC	=	src/Utils/Utils.cpp							\
		src/BracketParser/BracketParser.cpp			\
		src/BracketParser/Block/Block.cpp			\
		src/Errors/InvalidType.cpp					\
		src/Errors/InvalidValue.cpp					\
		src/Errors/UnwrapFailure.cpp				\

OBJ	=	$(SRC:.cpp=.o)

UT_SRC 	=	tests/main.cpp

UT_OBJ	=	$(UT_SRC:.cpp=.o)

OBJ	=	$(SRC:.cpp=.o)

CXXFLAGS	=	 -Wextra -Wall

CXXFLAGS	+=	 -I ./include

UT_NAME	=	unit_test

LIBFOLDER	=	./lib

CC	=	g++

LIBNAME	=	libparser.a

all	:	$(LIBNAME)

$(LIBNAME)	:	$(OBJ) $(MAIN)
	ar rc $(LIBNAME) $(OBJ)
	mv $(LIBNAME) $(LIBFOLDER)

clean	:
		$(RM) $(OBJ)
		$(RM) $(UT_OBJ)

fclean	:	clean
		$(RM) $(UT_NAME)
		$(RM) $(LIBFOLDER)/$(LIBNAME)

re	:	fclean all

tests_run:	CFLAGS += --coverage
tests_run:	LDFLAGS += -lgtest -lgtest_main -pthread -L$(LIBFOLDER) -lparser
tests_run	:	$(LIBNAME) $(UT_OBJ)
	$(CC) $(UT_OBJ) -o $(UT_NAME) $(LDFLAGS) $(CXXFLAGS) $(CFLAGS)
	./$(UT_NAME)

.PHONY	:	all clean fclean re

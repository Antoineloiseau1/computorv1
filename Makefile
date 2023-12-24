NAME	=	computor

SRCS	=	main.cpp lexer.cpp parser.cpp utils.cpp Term.cpp compute.cpp

OBJS	=	${SRCS:.cpp=.o}

CC		=	c++

FLAGS	=	-Wall -Werror -Wextra

RM		=	rm -rf

.cpp.o:
			${CC} ${FLAGS} -c $< -o ${<:.cpp=.o}

all:		${NAME}

${NAME}:	${OBJS}
			${CC} ${FLAGS} ${OBJS} -o ${NAME}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re


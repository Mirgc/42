SRCS	=	ft_printf.c

OBJS	= 	${SRCS:.c=.o}

NAME	= 	libftprintf.a

CC		= 	cc

AR		=	ar rcs

RANLIB	=	ranlib

CFLAGS	= 	-Wall -Wextra -Werror

LFLAGS	=	-I

all:		${NAME}

$(NAME):	${OBJS}
			${AR} ${NAME} ${OBJS}
			${RANLIB} ${NAME}	

clean:
		rm -f ${OBJS} ${BOBJS}
	
fclean:
		rm -f ${NAME}

re: 		fclean all

.PHONY:		all clean fclean

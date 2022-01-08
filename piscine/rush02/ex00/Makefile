SRCS	= main.o read_dict.o ft_parse.o write_number.o

OBJS	= ${SRCS:.c=.o}

NAME	= rush-02

RM		= rm -f

CFLAGS	= -Wall -Wextra -Werror

.c.o:
		${CC} ${CFLAGS} -c -o ${<:.c=.o}

${NAME}:	${OBJS}
			cc ${OBJS} ${CFLAGS} -o ${NAME}

clean:
		${RM} {OBJS}

fclean:
		${RM} ${NAME}

write_number.o:	write_number.c ft_h.h
				cc -c write_number.c ${CFLAGS}

ft_parse.o:		ft_parse.c ft_h.h
				cc -c ft_parse.c ${CFLAGS}

read_dict.o:	read_dict.c ft_h.h
				cc -c read_dict.c ${CFLAGS}

main.o:		main.c ft_h.h
		    cc -c main.c ${CFLAGS}

.PHONY:	all clean fclean 

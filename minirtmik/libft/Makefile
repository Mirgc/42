SRCS	=	ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_memccpy.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_split.c ft_strchr.c ft_strdup.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c ft_itoa.c ft_strmapi.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c get_next_line.c get_next_line_utils.c ft_isspacetab.c ft_atof.c ft_mini_atoi.c

BONS	=	ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstiter.c ft_lstdelone.c ft_lstclear.c ft_lstmap.c

OBJS	= 	${SRCS:.c=.o}

BOBJS	=	${BONS:.c=.o}

NAME	= 	libft.a

CC		= 	cc

AR		=	ar rcs

RANLIB	=	ranlib

CFLAGS	= 	-Wall -Wextra -Werror

LFLAGS	=	-I

all:		${NAME}

$(NAME):	${OBJS}
			${AR} ${NAME} ${OBJS}
			${RANLIB} ${NAME}	

bonus:		${BOBJS} ${OBJS}
			${AR} ${NAME} ${BOBJS} ${OBJS}
			${RANLIB} ${NAME}
clean:
		rm -f ${OBJS} ${BOBJS}
	
fclean:
		rm -f ${NAME}

re: 		fclean all

.PHONY:		all clean fclean

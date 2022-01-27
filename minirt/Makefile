CC = gcc
CFLAGS = -Wall -Wextra -Werror
SANITIZE    = -fsanitize=address -g3

NAME = minirt 

SRCS_DIR = src/
SRCS_FILE =	main.c \
			tuples.c

SRCS = $(addprefix $(SRCS_DIR), $(SRCS_FILE))
OBJS = $(SRCS:%.c=%.o)

$(NAME) :	$(OBJS)
			$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

all		:	$(NAME)

s:
	$(CC) $(CFLAGS) $(SANITIZE) -o $(NAME) $(OBJS)

clean	:	
			rm -rf $(OBJS)

fclean	:	clean
			rm -rf $(NAME)

re		:	fclean all

.PHONY	:	all clean fclean re


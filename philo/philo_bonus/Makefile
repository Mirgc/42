CC = gcc
CFLAGS = -Wall -Wextra -Werror
SANITIZE    = -fsanitize=address -g3

PTHEAD_FLAG = -pthread

NAME = philo

SRCS_DIR = src/
SRCS_FILE =	main.c \
			utils.c \
			philo.c \
			print.c

SRCS = $(addprefix $(SRCS_DIR), $(SRCS_FILE))
OBJS = $(SRCS:%.c=%.o)

$(NAME) :	$(OBJS)
			$(CC) $(CFLAGS) $(PTHEAD_FLAG) -o $(NAME) $(OBJS)

all		:	$(NAME)

s:
	$(CC) $(CFLAGS) $(PTHEAD_FLAG) $(SANITIZE) -o $(NAME) $(OBJS)

clean	:	
			rm -rf $(OBJS)

fclean	:	clean
			rm -rf $(NAME)

re		:	fclean all

.PHONY	:	all clean fclean re


NAME	= phonebook
CC		= clang++
CFLAGS	= -Wall -Wextra -Werror -g

SRCS	= tests.cpp \
	  Account.cpp
OBJS	= $(SRCS:cpp=o)


.PHONY: all
all: $(NAME)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $<

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

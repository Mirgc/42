NAME	= zombie
CC		= clang++
CFLAGS	= -Wall -Wextra -Werror

SRCS	= Zombie.cpp \
		  newZombie.cpp \
		  randomChump.cpp \
		  main.cpp
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

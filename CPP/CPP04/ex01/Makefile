NAME	= animal
CC		= clang++
CFLAGS	= -Wall -Wextra -Werror
SANITIZE = -fsanitize=address -g3

SRCS	= Animal.cpp \
		Dog.cpp \
		Cat.cpp \
		WrongAnimal.cpp \
		WrongCat.cpp \
		Brain.cpp \
		main.cpp

OBJS	= $(SRCS:cpp=o)

$(NAME): 
	$(CC) $(CFLAGS) $(SRCS) -o $(NAME)

all: $(NAME)

s: 
	$(CC) $(CFLAGS) $(SANITIZE) $(SRCS) -o $(NAME)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $<

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all

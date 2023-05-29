NAME	= PmergeMe
CC		= c++
CFLAGS	= -std=c++98 -Wall -Wextra -Werror 

SRCS	= main.cpp \
			PmergeMe.cpp
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

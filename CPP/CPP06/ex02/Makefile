NAME	= base
CC		= clang++
CFLAGS	= -Wall -Wextra -Werror

SRCS	= Base.cpp \
		A.cpp \
		B.cpp \
		C.cpp \
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

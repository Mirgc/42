NAME	= miniRT

HEAD	= includes

SRCDIR	= srcs/

LIB		= lib/

FILES	=	main.c \
			tuples.c \
			canvas.c \
			matrix.c \
			ray.c \
			light.c \
			world.c \
			camera.c \

SRCS	= $(addprefix $(SRCDIR), $(FILES))

OBJS	= ${SRCS:.c=.o}

CC		= gcc -g3 -fsanitize=address

RM		= rm -f

CFLAGS	= -I $(HEAD)
#CFLAGS	= -Wall -Wextra -Werror -I $(HEAD)

#FLAGS = -L $(LIB)libft -lft -L $(LIB)libvector -lvct

MACOS_MACRO = -D MACOS

LINUX_MACRO = -D LINUX

MACOS_FLAGS = -L $(LIB)minilibx_opengl_20191021 -lmlx -framework OpenGL -framework AppKit 

LINUX_FLAGS = -L $(LIB)minilibx-linux -lmlx -lm -lX11 -lXext

UNAME := $(shell uname)

ifeq ($(UNAME),Darwin)
	CFLAGS += $(MACOS_MACRO)
	FLAGS += $(MACOS_FLAGS)
endif
ifeq ($(UNAME),Linux)
	CFLAGS += $(LINUX_MACRO)
	FLAGS += $(LINUX_FLAGS)
endif

${NAME}:	${OBJS}
#			make -C $(LIB)libft
#			make -C $(LIB)libvector
			${CC} ${CFLAGS} $(OBJS) $(FLAGS) -o ${NAME}

all:		${NAME}

clean:
#			make clean -C $(LIB)libft
#			make clean -C $(LIB)libvector
			${RM} ${OBJS}

fclean:		clean
#			make fclean -C $(LIB)libft
#			make fclean -C $(LIB)libvector
			${RM} ${NAME}

re:			fclean all

PHONY:		all clean fclean re

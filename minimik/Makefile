NAME	= miniRT

HEAD	= includes

SRCDIR	= srcs/

LIB		= lib/

FILES	=	main.c \
		plane.c \
		ray.c \
		sphere.c \
		world.c \
		world_two.c \
		camera.c \
		color.c \
		create_tuple.c \
		cylinder.c \
		error.c \
		intersections.c \
		lights.c \
		materials.c \
		matrix_det.c \
		matrix_inver.c \
		matrix_trans.c \
		matrix_trans_two.c \
		matrix_utils.c \
		operation_tuple.c \
		operation_tuple_two.c \
		parse/parse.c \
		parse/parse_utils.c \
		parse/parse_info.c \
		parse/parse_obj.c \

SRCS	= $(addprefix $(SRCDIR), $(FILES))

OBJS	= ${SRCS:.c=.o}

CC		= gcc -g3 -fsanitize=address
#CC		= gcc 
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
			make -C ./libft
			cp libft/libft.a .
#			make -C $(LIB)libvector
			${CC} ${CFLAGS} $(OBJS) $(FLAGS) libft.a -o ${NAME}

all:		${NAME}

clean:
			make clean -C ./libft
#			make clean -C $(LIB)libft
#			make clean -C $(LIB)libvector
			${RM} ${OBJS}

fclean:		clean
			make fclean -C ./libft
#			make fclean -C $(LIB)libft
#			make fclean -C $(LIB)libvector
			${RM} ${NAME}

re:			fclean all

PHONY:		all clean fclean re

CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = fdf
INCLUDE = -I mlx
LIBS = libft/libft.a -framework OpenGL -framework AppKit
SRC = src
SRC_FILES = $(SRC)/main.c $(SRC)/draw.c $(SRC)/read.c $(SRC)/aux.c
OBJ_DIR = obj
OBJ_FILES = $(patsubst $(SRC)/%.c,$(OBJ_DIR)/%.o,$(SRC_FILES))

all : $(NAME)


$(NAME) : $(OBJ_FILES)
	@make -C libft
	@make -C mlx
	$(CC) -o $(NAME) $(OBJ_FILES) $(LIBS) mlx/libmlx.a

$(OBJ_DIR)/%.o: $(SRC)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDE) -o $@ -c $<

clean :
	rm -f $(OBJ_FILES)
	@make -C libft clean
	@make -C mlx clean

fclean : clean
	rm -f $(NAME)
	@make -C libft clean
	@make -C mlx clean

re : fclean all

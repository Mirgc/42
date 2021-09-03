S_NAME = server
C_NAME = client

FLAGS = -Wall -Wextra -Werror
INC =	-Iinclude/

S_SRC =	server.c ft_putnbr.c
C_SRC = client.c

S_OBJ_NAME = $(S_SRC:.c=.o)
C_OBJ_NAME = $(C_SRC:.c=.o)
S_OBJ = $(addprefix $(S_OBJ_DIR),$(S_OBJ_NAME))
C_OBJ = $(addprefix $(C_OBJ_DIR),$(C_OBJ_NAME))

S_SRC_DIR = src_server/
C_SRC_DIR = src_client/

S_OBJ_DIR = $(S_SRC_DIR)objs/
C_OBJ_DIR = $(C_SRC_DIR)objs/

all: $(S_NAME) $(C_NAME)

$(S_NAME): $(S_OBJ)
	@gcc -o $(S_NAME) $(S_OBJ)
	@echo "### server compiling finished! ###"

$(C_NAME): $(C_OBJ)
	@gcc -o $(C_NAME) $(C_OBJ)
	@echo "### client compiling finished! ###"

$(S_OBJ_DIR)%.o: $(S_SRC_DIR)%.c
	@mkdir -p $(S_OBJ_DIR)
	@echo "### Creating" [ $@ ] " ###"
	@gcc $(FLAGS) -o $@ -c $< $(INC)

$(C_OBJ_DIR)%.o: $(C_SRC_DIR)%.c
	@mkdir -p $(C_OBJ_DIR)
	@echo "### Creating" [ $@ ] " ###"
	@gcc $(FLAGS) -o $@ -c $<

clean:
	@rm -f $(S_OBJ) $(C_OBJ)
	@echo "### Removed object files ###"

fclean: clean
	@rm -f $(S_NAME) $(C_NAME)
	@echo "### Removed binary files ###"

re: fclean all

.PHONY: all clean fclean re


NAME =	push_swap
FLAGS = -Wall -Wextra -Werror
INC =	-Iincludes/

SRC =	push_swap.c options.c options2.c operations.c node.c\
 ft_swap_arr.c ft_split.c ft_sort.c ft_rot_push.c ft_list.c\
ft_divide.c ft_aux.c ft_swap2.c ft_swap1.c 

OBJ_NAME = $(SRC:.c=.o)
OBJ = $(addprefix $(OBJ_DIR),$(OBJ_NAME))

SRC_DIR = srcs/
OBJ_DIR = objs/

all: $(NAME)

$(NAME): $(OBJ)
	@gcc -o $(NAME) $(OBJ)
	@echo "##### push_swap compiling finished! #####"

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	@echo "##### Creating" [ $@ ] " #####"
	@gcc $(FLAGS) -o $@ -c $< $(INC)

clean:
	@rm -f $(OBJ)
	@echo "##### Removed object files #####"

fclean: clean
	@rm -f $(NAME)
	@echo "##### Removed binary files #####"

re: fclean all

.PHONY: all clean fclean re


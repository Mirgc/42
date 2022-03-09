# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: osurcouf <.@student.42lisboa.com>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/01 16:35:43 by osurcouf          #+#    #+#              #
#    Updated: 2021/06/30 15:23:17 by osurcouf         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# -*-🦕-*- Make MiniRT Sparkle -*-🦕-*- 

NAME	= miniRT

# -*- Definitions of variables -*-

SRCS_DIR	= srcs
SRCS		= ${addprefix ${SRCS_DIR}/,${SRCS_FIND}}
SRCS_FIND	= ${shell find . -type f \( -wholename "./srcs/*.c" -not -wholename "./ft_*bonus.c" -not -wholename "./libft/ft_*.c" \) | cut -d'/' -f3-}
SRCS_BONUS	= ${addprefix ${SRCS_DIR}/,${SRCS_BFIND}}
SRCS_BFIND	= ${shell find . -type f \( -wholename "./srcs/*.c" -not -wholename "./libft/ft_*.c" \) | cut -d'/' -f3-}

OBJS_DIR	= objs
OBJS		= ${addprefix ${OBJS_DIR}/,${SRCS_FIND:.c=.o}}
OBJS_BONUS	= ${addprefix ${OBJS_DIR}/,${SRCS_BFIND:.c=.o}}

HEADER		= include

LIBFT_DIR	= libft
LIBFT_LIB	= -Llibft -lft

CC			= gcc
RM			= rm -f
MAKE		= make
CFLAGS 		= -Wall -Wextra -Werror #-fsanitize=address -g

# Will allow to compile the right library according to if the OS is WSL/Linux or Mac
UNAME = ${shell uname}

# If Mac
ifeq ($(UNAME), Darwin)
OS			= Apple
INCLUDES	= -Ilibft -Iinclude -Iminilibx_mms
#INCLUDES	= -Ilibft -Iinclude -Lmlx -lmlx -framework OpenGL -framework AppKit 

MLX			= ./minilibx_mms
MLX_LIB		= -Lminilibx_mms -lmlx
MLX_FLAGS	= 

#If Linux
else
OS			= Linux
INCLUDES	= -Iinclude -I/usr/include -Imlx_linux -Ilibft

MLX_LIB		= -Lmlx_linux -lmlx_Linux -L/usr/lib
MLX_FLAGS	= -Imlx_linux -lXext -lX11 -lm -lz
endif

# Colors

GRAY		= \e[1;30m
GREEN 		= \e[1;32m
DARK_GREEN	= \e[0;32m
YELLOW		= \e[1;33m
BLUE		= \e[1;34m
PURPLE		= \e[1;35m
CYAN		= \e[1;36m
WHITE		= \e[1;37m
NORMAL		= \e[0;37m
END			= \e[0m

# -*- The Rules -*-

#	Implicit rules

# Create and compile objects files in a dedicated folder
${OBJS_DIR}/%.o: ${SRCS_DIR}/%.c 
			@mkdir -p objs
			@mkdir -p objs/parsing
			@mkdir -p objs/utils
			@mkdir -p objs/intersect_obj
			@mkdir -p objs/raytracing
			@${CC} ${CFLAGS} ${INCLUDES} -O3 -c $< -o $@

#	Active rules

all:		${NAME} test

# Make libft + compile miniRT
${NAME}:	${OBJS}
			@${MAKE} bonus -C ${LIBFT_DIR}
ifeq ($(UNAME), Darwin)
			@printf "\n	${WHITE}[${GREEN}"
			@printf "Compiling minilibx${END}]\n\n"
			@printf "${GRAY}"
			@${MAKE} -C ${MLX}
			@printf "${END}"
			cp ${MLX}/libmlx.dylib ./
endif
			@printf "\n	${WHITE}[${GREEN}"
			@printf "Compiling miniRT${END}]\n\n"
			@printf "${GRAY}"
			$(CC) ${CFLAGS} ${OBJS} ${MLX_LIB} ${LIBFT_LIB} ${MLX_FLAGS} -o $(NAME)
			@printf "\n	🎉 [${DARK_GREEN}SUCCESS${END}] 🎉\n"
			@printf "	${GRAY}________________${END}\n"

test:		${NAME}
			@printf "\n	📚 [${PURPLE}INSTRUCTIONS${END}] 📚\n"
			@printf "\n🦕🍭	${YELLOW}To start miniRT on MacOS or Linux${END}\n"
			@printf "	[${GRAY}./miniRT ./scenes/example.rt${END}]\n"
			@printf "\n🍭🦄	${CYAN}To start miniRT on WSL${END}\n" 
			@printf "	[${GRAY}Launch vcxsrv.exe${END}]\n"
			@printf "🦄🍭	${CYAN}Copy the following command line${END}\n" 
			@printf "	[${GRAY}DISPLAY=\$$(cat /etc/resolv.conf | grep nameserver | awk '{print \$$2}'):0 ./miniRT ./scenes/minimalist.rt${END}]\n"
			@printf "\n🦕🍭${NORMAL}By Ophélie Surcouf @ 42Lisboa${END} 🍭🦕\n"

bonus:		${NAME} test

#	Cleaning rules

clean:
			@printf "\n${WHITE}"
			@${MAKE} clean -C ${LIBFT_DIR}
ifeq ($(UNAME), Darwin)
			@printf "\n	${WHITE}[${BLUE}"
			@printf "Cleaning minilibx objects${END}]\n\n"
			@printf "${GRAY}"
			@${MAKE} clean -C ${MLX}
			@printf "${END}"
endif
			@printf "\n	${WHITE}[${BLUE}"
			@printf "Cleaning miniRT objects${END}]\n\n"
			@printf "${GRAY}"
			${RM} ${OBJS} ${OBJS_BONUS}
			@rm -rf objs
			@printf "${END}"

fclean:		clean
			@printf "\n${WHITE}"
			@${MAKE} fclean_no_clean -C ${LIBFT_DIR}
ifeq ($(UNAME), Darwin)
			@printf "\n	${WHITE}[${BLUE}"
			@printf "Cleaning minilibx output files${END}]\n\n"
			@printf "${GRAY}"
			${RM} libmlx.dylib
			@printf "\n${END}"
endif
			@printf "\n	${WHITE}[${BLUE}"
			@printf "Cleaning miniRT output files${END}]\n\n"
			@printf "${GRAY}"
			${RM} ${NAME}
			@printf "\n${END}"

re:			fclean all

.PHONY:		libft all clean fclean re

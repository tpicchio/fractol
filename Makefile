# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tpicchio <tpicchio@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/22 17:09:08 by tpicchio          #+#    #+#              #
#    Updated: 2024/01/24 10:28:32 by tpicchio         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = 			fractol

CC = 			cc
FLAGS = 		-Wall -Wextra -Werror
MLX  = 			-Lminilibx-linux minilibx-linux/libmlx_Linux.a -L/usr/lib -Iminilibx-linux -lXext -lX11 -lm -lz -Iinclude

LIBFT_PATH		:= ./libft
LIBFT			:= $(LIBFT_PATH)/libft.a

LIBMLX_PATH		:= ./minilibx-linux
LIBMLX			:= $(LIBMLX_PATH)/libmlx_Linux.a

SRC =			src/main.c \
				src/setup.c \
				src/render.c \
				src/burningship.c \
				src/utils.c \
				src/events.c

$(NAME):		$(LIBFT) $(SRC) $(LIBMLX)
		$(CC) $(FLAGS) $(SRC) $(LIBFT) $(MLX) -o $(NAME)
		echo
		echo "${BOLD}Created  -> ${RED}$(NAME)${NO_COLOR}"

$(LIBFT):
				make -C $(LIBFT_PATH) all

$(LIBMLX):
				@make -C $(LIBMLX_PATH) all > /dev/null 2>&1
				echo
				echo "${BOLD}Created  -> ${GREEN}libmlx_Linux.a${NO_COLOR}"

all: 			$(NAME)

re: 			fclean all

clean:
		if [ -n "$$(find $(LIBFT_PATH) -name '*.o' -print -quit)" ]; then \
			make -C $(LIBFT_PATH) clean; \
			echo; \
			echo "${BOLD}${YELLOW}Cleaned object files${NO_COLOR}"; \
		fi

fclean:			clean
		if [ -e $(LIBFT) ]; then \
			make -C $(LIBFT_PATH) fclean; \
			echo; \
			echo "${BOLD}${YELLOW}Removed  -> ${BLUE}libft.a${NO_COLOR}"; \
		fi
		if [ -e $(LIBMLX) ]; then \
			make -C $(LIBMLX_PATH) clean > /dev/null; \
			echo; \
			echo "${BOLD}${YELLOW}Removed  -> ${GREEN}libmlx_Linux.a${NO_COLOR}"; \
		fi
		if [ -e $(NAME) ]; then \
			rm -f $(NAME); \
			echo; \
			echo "${BOLD}${YELLOW}Removed  -> ${RED}$(NAME)${NO_COLOR}"; \
		fi

.PHONY:	all clean fclean re

.SILENT:

#RED 			:= ${shell tput setaf 1}
#YELLOW			:= ${shell tput setaf 3}
#BLUE			:= ${shell tput setaf 4}
#GREEN			:= ${shell tput setaf 2}
#NO_COLOR		:= ${shell tput sgr0}
#BOLD			:= ${shell tput bold}

RED 		= \033[1;31m
GREEN 		= \033[1;32m
YELLOW		= \033[1;33m
BLUE		= \033[1;34m
NO_COLOR	= \033[0m
BOLD		= \033[1m

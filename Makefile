# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tpicchio <tpicchio@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/22 17:09:08 by tpicchio          #+#    #+#              #
#    Updated: 2024/02/14 14:13:39 by tpicchio         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Target name
NAME = fractol

# Compiler
CC = cc

# Compilation flags
FLAGS = -Wall -Wextra -Werror

# MiniLibX configuration
MLX = -Lminilibx-linux minilibx-linux/libmlx_Linux.a -L/usr/lib -Iminilibx-linux -lXext -lX11 -lm -lz -Iinclude

# Library paths
LIBFT_PATH := ./libft
LIBMLX_PATH := ./minilibx-linux

# Library files
LIBFT := $(LIBFT_PATH)/libft.a
LIBMLX := $(LIBMLX_PATH)/libmlx_Linux.a

# MiniLibX repository URL
MLX_URL := https://github.com/42Paris/minilibx-linux.git

# Source files
SRC = src/main.c \
      src/setup.c \
      src/render.c \
      src/burningship.c \
      src/utils.c \
      src/events.c

THREAD = src/main.c \
      src/setup.c \
      src/utils.c \
      src/events.c \
	  thread/render_thread.c \
	  thread/burningship_thread.c

# Main target
$(NAME): $(LIBMLX) $(LIBFT) $(SRC)
	$(CC) $(FLAGS) $(SRC) $(LIBFT) $(MLX) -o $(NAME)
	echo
	echo "${BOLD}Created  -> ${RED}$(NAME)${NO_COLOR}"

# Build the LibFT library
$(LIBFT):
	@make -C $(LIBFT_PATH) all > /dev/null 2>&1
	echo
	echo "${BOLD}Created  -> ${BLUE}libft.a${NO_COLOR}"

# Build the MiniLibX library
$(LIBMLX):
	@if [ ! -d "$(LIBMLX_PATH)" ]; then \
		$(MAKE) $(LIBMLX_PATH); \
	fi
	@make -C $(LIBMLX_PATH) all > /dev/null 2>&1
	echo
	echo "${BOLD}Created  -> ${GREEN}libmlx_Linux.a${NO_COLOR}"

# Download MiniLibX if not present
$(LIBMLX_PATH):
	@echo "${GREEN}${BOLD}Downloading minilibx${NO_COLOR}"
	git clone $(MLX_URL) $(LIBMLX_PATH) > /dev/null 2>&1

# Compile multi thread version
thread: $(LIBMLX) $(LIBFT) $(SRC)
	$(CC) $(FLAGS) -pthread -D DIM=1000 $(THREAD) $(LIBFT) $(MLX) -o fractol_thread
	echo
	echo "${BOLD}Created  -> ${RED}fractol_thread${NO_COLOR}"
	

# Alias for download target
download: $(LIBMLX_PATH)

# Build all target
all: $(NAME)

# Clean and rebuild target
re: fclean all

# Clean object files
clean:
	if [ -n "$$(find $(LIBFT_PATH) -name '*.o' -print -quit)" ]; then \
		make -C $(LIBFT_PATH) clean > /dev/null 2>&1; \
		echo; \
		echo "${BOLD}${YELLOW}Cleaned object files${NO_COLOR}"; \
	fi

# Full clean
fclean: clean
	if [ -e $(LIBFT) ]; then \
		make -C $(LIBFT_PATH) fclean > /dev/null 2>&1; \
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
	if [ -e fractol_thread ]; then \
		rm -f fractol_thread; \
		echo; \
		echo "${BOLD}${YELLOW}Removed  -> ${RED}fractol_thread${NO_COLOR}"; \
	fi

# Declare phony target
.PHONY: all clean fclean re download thread

# Silence all commands
.SILENT:

# ANSI color codes
RED = \033[1;31m
GREEN = \033[1;32m
YELLOW = \033[1;33m
BLUE = \033[1;34m
NO_COLOR = \033[0m
BOLD = \033[1m

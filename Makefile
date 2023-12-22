# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tpicchio <tpicchio@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/22 17:09:08 by tpicchio          #+#    #+#              #
#    Updated: 2023/12/22 17:21:27 by tpicchio         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

SRC = src/main.c src/ft_fractal_init.c src/ft_fractal_render.c src/ft_map.c src/ft_key_handle.c src/ft_mouse_handle.c src/ft_mouse_move.c src/ft_close.c

#OBJ = $(SRC:.c=.o)

CC = gcc

CFLAGS = -Wall -Wextra -Werror

MLX = -lmlx -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME):
    $(CC) $(CFLAGS) -o $(NAME) $(SRC) $(MLX)

%.o: %.c
    $(CC) $(CFLAGS) -c $< -o $@

clean:
    rm -f $(OBJ)

fclean: clean
    rm -f $(NAME)

re: fclean all

#cc -lX11 -lXext -Iminilibx-linux -Iinclude src/*.c libft/libft.a minilibx-linux/libmlx_Linux.a -o fractol
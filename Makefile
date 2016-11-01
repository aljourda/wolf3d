# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aljourda <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/09/30 14:36:09 by aljourda          #+#    #+#              #
#    Updated: 2016/10/17 14:07:34 by aljourda         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=wolf3d
SRC= srcs/inputs.c \
	srcs/map.c \
	srcs/ray.c \
	srcs/camera.c \
	srcs/wolf.c

CC=clang
CFLAGS=-I libft/includes -I minilibx_macos/ -I get_next_line/ -I includes/ -Wall -Wextra -Werror
OBJ=$(SRC:.c=.o)
LDFLAGS=-L libft/ -L minilibx_macos/
LIBS=-lft -lm -lmlx -framework OpenGL -framework AppKit

$(NAME): $(OBJ)
	make -C libft/
	make -C minilibx_macos/
	$(CC) -o $(NAME) $(OBJ) $(LDFLAGS) $(LIBS)

all: $(NAME)

clean:
	make clean -C libft/
	make clean -C minilibx_macos/
	rm -f $(OBJ)

fclean: clean
	make fclean -C libft/
	rm -f $(NAME)

re: fclean all

%.o: %.c
	$(CC) -c $(CFLAGS) $^ -o $@

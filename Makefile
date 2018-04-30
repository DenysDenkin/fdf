# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ddenkin <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/23 21:12:41 by akorunsk          #+#    #+#              #
#    Updated: 2018/03/27 17:05:00 by ddenkin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

LIBNAME = libft.a
OBJ = $(SRC:.c=.o)
FLAGS = -Wall -Wextra -Werror
SRC = draw.c \
	  draw_utils.c \
	  free.c \
	  helper.c \
	  keyboard.c \
	  mouse.c \
	  matr_transform.c \
	  reader.c \
	  reader_utils.c

all: liball $(NAME)

obj: $(OBJ)

$(NAME) : $(LIBNAME) $(OBJ)
		gcc -O3 $(FLAGS) $^ -o $(NAME) -lmlx -framework AppKit -framework OpenGL

%.o: %.c
		gcc $(FLAGS) -o $@ -c $<

clean: libclean
		rm -rf $(OBJ)

fclean: libfclean clean
		rm -rf $(NAME)

re: fclean all

$(LIBNAME): liball

liball:
		@make -C libft/ all

libclean:
		@make -C libft/ clean

libfclean:
		@make -C libft/ fclean

libre: libfclean liball

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nnqisha <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/10 18:15:34 by nnqisha           #+#    #+#              #
#    Updated: 2018/09/16 16:38:03 by nnqisha          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = wolf3D

FLAGS = -Wall -Werror -Wextra -lSDL2 -I includes/ -I includes/SDL2/ -L ~/lib -ggdb3

LIB = libft/libft.a

OBJ = wolf_main.o color.o calc_distance.o ft_event_handlers.o ft_draw.o init_sdl.o read.o ft_movement.o

SDL = SDL2-2.0.8

all:
	make -C libft
	make $(NAME)

$(NAME): $(SDL) $(OBJ) $(LIB)
	@if [ ! -d includes/SDL2 ]; then make SDL; fi;
	@gcc -o $(NAME) $(OBJ) $(FLAGS) $(LIB)

$(OBJ): %.o: %.c includes/wolf.h
	gcc -c $*.c -o $@

SDL:
	curl -O https://libsdl.org/release/SDL2-2.0.8.tar.gz && \
	gunzip -c SDL2-2.0.8.tar.gz | tar xf - && \
	cd SDL2-2.0.8 && \
	mkdir build && \
	cd build && \
	../configure && \
	make
	mkdir -p ~/lib/
	cp SDL2-2.0.8/build/build/.libs/libSDL2-2.0.0.dylib ~/lib/
	ln -F -s ~/lib/libSDL2-2.0.0.dylib ~/lib/libSDL2.dylib
	mkdir -p includes/SDL2
	cp SDL2-2.0.8/include/*.h includes/SDL2/

clean:
	rm -f $(OBJ)
	$(MAKE) -C ./libft clean
	$(MAKE) -C ./libft clean

fclean: clean
	rm -rf $(NAME)
	$(MAKE) -C ./libft fclean

re: fclean all

co:
	$(CC) $(FILES) $(FLAGS)
	./$(NAME)
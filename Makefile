# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cfeijoo <cfeijoo@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/11/28 05:03:25 by cfeijoo           #+#    #+#              #
#    Updated: 2014/02/16 16:59:04 by cfeijoo          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = raytracer

INCLUDEFOLDERS = -I./includes/ -I./libft/includes/ -I./guava/includes/
LIBFOLDERS = -L./libft/ -L/usr/X11/lib/ -L/usr/X11/include
LIBS =  -lmlx -lXext -lX11 -lft

CC = gcc
CFLAGS = -Wall -Werror -Wextra

CFILES =	main.c							\
			transformations_camera.c		\
			transformations_vectors.c

OFILES = $(CFILES:.c=.o)

all: $(NAME)

$(NAME) :
	$(CC) -c $(CFILES) $(INCLUDEFOLDERS) $(CFLAGS)
	$(CC) $(OFILES) $(INCLUDEFOLDERS) $(LIBFOLDERS) $(LIBS) $(CFLAGS) -o $(NAME)

updatelibs :
	cd libft/ && git pull
	make -C libft/ re

complibs :
	make -C libft/ re

clean :
	rm -f $(OFILES)

fclean : clean
	rm -f $(NAME)

re : fclean all

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oelkhiar <oelkhiar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/18 14:31:29 by oelkhiar          #+#    #+#              #
#    Updated: 2023/07/19 15:51:53 by oelkhiar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

SRCS = 	main.c \
		assets.c \
		julia.c \
		mandelbrot.c

OBJS = $(SRCS:.c=.o)

CC = cc

CFLAGS = -Wall -Wextra -Werror

MLX = -lmlx -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME):$(OBJS) fractol.h
	$(CC) $(CFLAGS) $(OBJS) -o $@ $(MLX)

clean:
	@rm -f $(OBJS)

fclean:clean
	@rm -f $(NAME)

re: fclean all

.phony: re clean fclean all
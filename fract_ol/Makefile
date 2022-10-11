# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oturkan <oturkan@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/14 10:49:26 by oturkan           #+#    #+#              #
#    Updated: 2022/07/14 10:53:50 by oturkan          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

CC = gcc

CFLAGS = -Wall -Werror -Wextra

SRCS = fractol.c utils.c user.c print.c loop.c

OBJS = $(SRCS:.c=.o)

MLX = -framework OpenGL -framework AppKit

LIB = mlx/libmlx.a

all : $(LIB) $(NAME)

$(LIB) :
	make -C mlx/

$(NAME) : $(OBJS)
		$(CC) $(OBJS) $(MLX) -o $(NAME) $(LIB)

clean :
		rm -rf $(OBJS)
		make -C ./mlx clean

fclean : clean
		rm -rf $(NAME)
		
re : fclean all

%.o: %.c
	$(CC) $(CFLAGS) -I./mlx -c $< -o $@

.PHONY : all clean fclean
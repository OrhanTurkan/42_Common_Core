# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oturkan <oturkan@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/02 11:17:06 by oturkan           #+#    #+#              #
#    Updated: 2022/07/02 11:17:07 by oturkan          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = gcc

CFLAGS = -Wall -Werror -Wextra

SRCS = push_swap.c control.c values.c utils.c ft_split.c bubble.c start.c all_up_down.c push.c helper.c reverse_rotate.c reverse.c swap.c

OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
		$(CC) $(OBJS) -o $(NAME)
clean :
		rm -rf $(OBJS)
fclean : clean
		rm -rf $(NAME)
re : fclean all

.PHONY : all clean fclean

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oturkan <oturkan@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/08 14:21:04 by oturkan           #+#    #+#              #
#    Updated: 2022/09/24 15:01:04 by oturkan          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	philo

SRCS	=	philo.c utils.c control.c angel.c god.c eat_sleep_think.c

OBJS = $(SRCS:.c=.o)

CC		= 	gcc
CFLAGS 	=	-Wall -Wextra -Werror

$(NAME)	:	$(OBJS)
			$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

all		:	$(NAME)
			
clean	:	
			rm -rf $(OBJS)

fclean	:	clean
			rm -rf $(NAME)

re		:	fclean	all

.Phony	:	all clean fclean re
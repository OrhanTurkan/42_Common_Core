# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oturkan <oturkan@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/20 14:26:17 by oturkan           #+#    #+#              #
#    Updated: 2022/02/21 14:02:26 by oturkan          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SSRC	=	server.c minitalk_utils.c
CSRC	=	client.c minitalk_utils.c

SERVER	=	$(CC) $(CFLAGS) client.c minitalk_utils.c -o client
CLIENT	=	$(CC) $(CFLAGS) server.c minitalk_utils.c -o server

CC		= 	gcc
CFLAGS 	=	-Wall -Wextra -Werror

all		:
			$(CLIENT)
			$(SERVER)
clean	:	
			rm -rf server client

fclean	:	clean

re		:	fclean	all

.Phony	:	all clean fclean re
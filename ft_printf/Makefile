# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oturkan <oturkan@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/29 17:11:39 by oturkan           #+#    #+#              #
#    Updated: 2022/01/30 15:15:07 by oturkan          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libftprintf.a
LIBFT	= libft/libft.a
CC		= gcc
RM		= rm -rf
CFLAGS	= -Wall -Wextra -Werror
SOURCES = ft_printf.c ft_printf_utils.c
AR 		= ar -rcs
COPY	= cp
M	= make -C
O_FILES = $(SOURCES:.c=.o)

all: $(NAME)

$(NAME): $(O_FILES) $(LIBFT)
	$(COPY) $(LIBFT) ./$(NAME)
	$(AR) $(NAME) $(O_FILES)

$(LIBFT):
	$(M) libft/ bonus

fclean: clean
	$(RM) $(NAME)
	$(M) libft/ fclean

clean:
	$(RM) $(O_FILES)
	$(M) libft/ clean

re: fclean all

.PHONY: all clean fclean re
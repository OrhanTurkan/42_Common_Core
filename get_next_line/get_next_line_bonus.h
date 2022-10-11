/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oturkan <oturkan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 13:04:13 by oturkan           #+#    #+#             */
/*   Updated: 2022/02/07 13:04:13 by oturkan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <stddef.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*get_next_line(int fd);
char	*oku(int fd, char *tut);
char	*yedek(char *tut);
char	*ayikla(char *tut);
size_t	ft_strlen(const char *s);
int		ft_strchr(const char *s, int c);
size_t	ft_strlcpy(char	*dst, const char *src, size_t dstsize);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_free(char *s);

#endif

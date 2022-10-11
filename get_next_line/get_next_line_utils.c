/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oturkan <oturkan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 14:05:40 by oturkan           #+#    #+#             */
/*   Updated: 2022/02/07 14:40:03 by oturkan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] == c)
			return (1);
		i++;
	}
	return (0);
}

size_t	ft_strlcpy(char	*dst, const char *src, size_t	dstsize)
{
	size_t	srcsize;
	size_t	i;

	srcsize = ft_strlen(src);
	if (!dstsize)
		return (srcsize);
	i = 0;
	while (src[i] && i < (dstsize - 1))
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (srcsize);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*p;
	int		len1;
	int		len2;

	if (!s1)
	{
		s1 = (char *)malloc(1);
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (0);
	len1 = (ft_strlen(s1));
	len2 = (ft_strlen(s2));
	p = (char *)malloc(len1 + len2 + 1);
	if (p == 0)
		return (0);
	ft_strlcpy(p, s1, len1 + 1);
	ft_strlcpy(&p[len1], s2, len2 + 1);
	free(s1);
	return (p);
}

char	*ft_free(char *s)
{
	free(s);
	return (0);
}

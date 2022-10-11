/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oturkan <oturkan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 12:56:07 by oturkan           #+#    #+#             */
/*   Updated: 2022/01/21 17:19:53 by oturkan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	is_char(char c, const char *set)
{
	while (*set)
		if (c == *set++)
			return (1);
	return (0);
}

char	*ft_strtrim(char const *s, char const *set)
{
	char	*p;
	size_t	a;

	if (s == 0 || set == 0)
		return (0);
	while (is_char(*s, set) && *s)
		s++;
	a = ft_strlen(s);
	while (is_char(s[a - 1], set) && a != 0)
		a--;
	p = (char *)malloc(sizeof(char) * (a + 1));
	if (p == 0)
		return (0);
	ft_strlcpy(p, s, a + 1);
	return (p);
}

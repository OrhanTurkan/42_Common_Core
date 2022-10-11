/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oturkan <oturkan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 12:56:34 by oturkan           #+#    #+#             */
/*   Updated: 2022/01/06 12:56:34 by oturkan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		a;
	int		b;
	char	*str;

	if (!s1 || !s2)
		return (0);
	a = ft_strlen((char *)s1);
	b = ft_strlen((char *)s2);
	str = (char *)malloc(a + b + 1);
	if (!str)
		return (0);
	ft_strlcpy(str, s1, a + 1);
	ft_strlcpy(&str[a], s2, b + 1);
	return (str);
}

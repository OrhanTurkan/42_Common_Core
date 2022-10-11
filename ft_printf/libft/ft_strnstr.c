/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oturkan <oturkan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 12:56:14 by oturkan           #+#    #+#             */
/*   Updated: 2022/01/08 13:16:15 by oturkan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	size;

	i = 0;
	size = ft_strlen(needle);
	if (!(size))
	{
		return ((char *)haystack);
	}
	while (haystack[i] && i < len)
	{
		j = 0;
		while ((needle[j] == haystack[i + j]) && (i + j < len))
		{
			if (j == size - 1)
				return ((char *)(haystack + i));
			j++;
		}
		i++;
	}
	return (0);
}

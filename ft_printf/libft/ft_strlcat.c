/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oturkan <oturkan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 12:56:31 by oturkan           #+#    #+#             */
/*   Updated: 2022/01/08 18:17:46 by oturkan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	len;
	size_t	i;

	i = 0;
	len = ft_strlen(dest);
	if (size <= len)
		return (size + ft_strlen(src));
	while (src[i] != 0 && len + 1 < size)
		dest[len++] = src[i++];
	dest[len] = 0;
	return (ft_strlen(dest) + ft_strlen(&src[i]));
}

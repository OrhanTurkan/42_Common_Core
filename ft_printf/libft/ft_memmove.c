/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oturkan <oturkan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 20:36:55 by oturkan           #+#    #+#             */
/*   Updated: 2022/01/15 18:00:50 by oturkan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*dst2;
	unsigned char	*src2;

	dst2 = (unsigned char *)dst;
	src2 = (unsigned char *)src;
	if (dst == src || !len)
		return (dst);
	if (src < dst)
	{
		src2 = src2 + len - 1;
		dst2 = dst2 + len - 1;
		while (len--)
			*dst2-- = *src2--;
	}
	else if (src >= dst)
	{
		while (len--)
			*dst2++ = *src2++;
	}
	return (dst);
}

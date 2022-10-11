/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oturkan <oturkan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 11:17:18 by oturkan           #+#    #+#             */
/*   Updated: 2022/07/13 11:01:06 by oturkan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	srcsize;
	size_t	i;

	srcsize = ft_strlen(src);
	i = 0;
	if (!dst || !src)
		return (0);
	if (dstsize != 0)
	{
		while (src[i] && i < (dstsize - 1))
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = 0;
	}
	return (srcsize);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_atoi(t_p *p, const char *nptr)
{
	int				eksi;
	int				i;
	long long int	sonuc;

	i = 0;
	eksi = 1;
	sonuc = 0;
	while ((nptr[i] <= 13 && nptr[i] >= 9) || nptr[i] == 32)
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			eksi *= -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		sonuc = sonuc * 10 + (nptr[i] - 48);
		if (sonuc > 2147483647)
			ft_exit(p, 1);
		else if (sonuc < -2147483648)
			ft_exit(p, 1);
		i++;
	}
	return (sonuc * eksi);
}

void	ft_swap(t_p *p, int a, int b)
{
	int	temp;

	temp = p->sorted[a];
	p->sorted[a] = p->sorted[b];
	p->sorted[b] = temp;
}

int	average(int *stack, int size)
{
	int	r;
	int	i;

	i = 0;
	r = 0;
	while (i < size)
	{
		r += stack[i];
		i++;
	}
	return (r / size);
}

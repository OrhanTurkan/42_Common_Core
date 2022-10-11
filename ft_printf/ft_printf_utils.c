/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oturkan <oturkan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 17:36:36 by oturkan           #+#    #+#             */
/*   Updated: 2022/01/30 13:54:59 by oturkan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	string(const char *str)
{
	int	sayac;

	if (str == NULL)
		str = "(null)";
	sayac = 0;
	while (*str)
	{
		write(1, str, 1);
		sayac++;
		str++;
	}
	return (sayac);
}

int	karakter(char c)
{
	write(1, &c, 1);
	return (1);
}

int	integer(int nbr)
{
	int		sayac;

	sayac = 0;
	if (nbr == -2147483648)
	{
		sayac += string("-2");
		nbr = 147483648;
	}
	if (nbr < 0)
	{
		sayac += karakter('-');
		nbr = -nbr;
	}
	if (nbr > 9)
		sayac += integer(nbr / 10);
	sayac += karakter((nbr % 10) + '0');
	return (sayac);
}

int	uns(unsigned int nbr, char *base)
{
	int				sayac;
	unsigned int	len;

	sayac = 0;
	len = ft_strlen(base);
	if (nbr > (len - 1))
		sayac += uns(nbr / len, base);
	sayac += karakter(base[nbr % len]);
	return (sayac);
}

int	pointer(void *ptr)
{
	unsigned long	p;
	int				sayac;

	sayac = 0;
	p = (unsigned long)ptr;
	if (p > 15)
		sayac += pointer((void *)(p / 16));
	sayac += karakter("0123456789abcdef"[p % 16]);
	return (sayac);
}

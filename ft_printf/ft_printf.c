/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oturkan <oturkan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 14:21:37 by oturkan           #+#    #+#             */
/*   Updated: 2022/01/30 14:30:59 by oturkan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	kontrol(char c, va_list ap)
{
	if (c == 'c')
		return (karakter(va_arg(ap, int)));
	else if (c == 's')
		return (string(va_arg(ap, char *)));
	else if (c == 'p')
	{
		string("0x");
		return (pointer(va_arg(ap, void *)) + 2);
	}
	else if (c == 'd' || c == 'i')
		return (integer(va_arg(ap, int)));
	else if (c == 'u')
		return (uns(va_arg(ap, unsigned int), "0123456789"));
	else if (c == 'x')
		return (uns(va_arg(ap, unsigned int), "0123456789abcdef"));
	else if (c == 'X')
		return (uns(va_arg(ap, unsigned int), "0123456789ABCDEF"));
	else if (c == '%')
		return (karakter('%'));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	int		sayac;
	va_list	ap;

	sayac = 0;
	va_start(ap, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			sayac += kontrol(*format, ap);
		}
		else
		{
			sayac += karakter(*format);
		}
		format++;
	}
	va_end(ap);
	return (sayac);
}

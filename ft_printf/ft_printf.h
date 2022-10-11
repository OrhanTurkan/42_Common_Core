/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oturkan <oturkan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 14:23:53 by oturkan           #+#    #+#             */
/*   Updated: 2022/01/30 14:35:31 by oturkan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include "libft/libft.h"

int	ft_printf(const char *format, ...);
int	kontrol(char c, va_list ap);
int	karakter(char c);
int	string(const char *str);
int	pointer(void *ptr);
int	integer(int nbr);
int	uns(unsigned int nbr, char *base);

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oturkan <oturkan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 10:49:18 by oturkan           #+#    #+#             */
/*   Updated: 2022/07/14 10:52:21 by oturkan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_strcmp(char const *s1, char const *s2)
{
	int	i;

	if (s1 == 0 || s2 == 0)
		return (0);
	i = 0;
	while (s1[i] == s2[i] && s1[i])
		i++;
	if (s1[i] && s2[i])
		return (1);
	else
		return (0);
}

long double	ft_abs(long double c)
{
	if (c < 0)
		return (c * -1);
	return (c);
}

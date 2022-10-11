/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oturkan <oturkan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 14:20:32 by oturkan           #+#    #+#             */
/*   Updated: 2022/02/21 15:58:37 by oturkan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	char2bit(int c, int pid)
{
	int				i;
	unsigned char	tmp;

	tmp = c;
	i = 128;
	while (i > 0)
	{
		if (tmp / i)
		{
			kill(pid, SIGUSR1);
			tmp -= i;
		}
		else
			kill(pid, SIGUSR2);
		usleep(100);
		i /= 2;
	}
}

int	main(int c, char **args)
{
	int		pid;
	int		i;
	char	*str;

	if (c != 3)
		return (-1);
	i = 0;
	while (args[1][i++])
	{
		if (!ft_strchr("0123456789", args[1][i]))
			return (-1);
	}
	pid = ft_atoi(args[1]);
	str = args[2];
	while (*str)
	{
		char2bit(*str, pid);
		str++;
	}
	return (0);
}

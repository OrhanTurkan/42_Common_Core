/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oturkan <oturkan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 18:00:52 by oturkan           #+#    #+#             */
/*   Updated: 2022/09/24 15:49:50 by oturkan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	fail_detect2(int c, char **args)
{
	int	i;
	int	j;

	i = 1;
	while (i < c)
	{
		j = 0;
		while (args[i][j])
		{
			if (args[i][j] == 43)
			{
				if (args[i][j + 1] == 32 || args[i][j + 1] == 45
					|| args[i][j + 1] == 0 || args[i][j + 1] == 43)
					return (0);
			}
			if (args[i][j] > 47 && args[i][j] < 58)
			{
				if (args[i][j + 1] == 43)
					return (0);
			}
		j++;
		}
	i++;
	}
	return (1);
}

static int	fail_detect(int c, char **args)
{
	int	i;
	int	j;

	i = 1;
	while (i < c)
	{
		j = 0;
		while (args[i][j])
		{
			if (args[i][j] == 45)
				return (0);
			if (args[i][j] > 47 && args[i][j] < 58)
			{
				if (args[i][j + 1] == 45)
					return (0);
			}
		j++;
		}
	i++;
	}
	return (fail_detect2(c, args));
}

int	is_num(char **args, int c)
{
	int	i;
	int	j;

	i = 1;
	while (i < c)
	{
		j = 0;
		while (args[i][j])
		{
			if (args[i][j] > 47 && args[i][j] < 58)
				j++;
			else if (args[i][j] == 45 || args[i][j] == 43)
				j++;
			else if (args[i][j] == 32)
				j++;
			else
				return (0);
		}
	i++;
	}
	return (fail_detect(c, args));
}

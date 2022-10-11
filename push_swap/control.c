/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oturkan <oturkan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 11:16:48 by oturkan           #+#    #+#             */
/*   Updated: 2022/07/08 16:37:36 by oturkan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_digit_minus(int c, char **args)
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
				ft_only_exit();
		}
	i++;
	}
	return (1);
}

int	fail_detect(int c, char **args)
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
			{
				if (args[i][j + 1] == 32 || args[i][j + 1] == 43
					|| args[i][j + 1] == 0 || args[i][j + 1] == 45)
					ft_only_exit();
			}
			if (args[i][j] > 47 && args[i][j] < 58)
			{
				if (args[i][j + 1] == 45)
					ft_only_exit();
			}
		j++;
		}
	i++;
	}
	return (fail_detect2(c, args));
}

int	fail_detect2(int c, char **args)
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
					ft_only_exit();
			}
			if (args[i][j] > 47 && args[i][j] < 58)
			{
				if (args[i][j + 1] == 43)
					ft_only_exit();
			}
		j++;
		}
	i++;
	}
	return (1);
}

void	double_control(t_p *p)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (i < p->size)
	{
		j = i + 1;
		while (j < p->size)
		{
			if (p->values[i] == p->values[j])
				ft_exit(p, 1);
			else
				j++;
		}
		i++;
	}
	bubble_sort(p);
	is_already_sorted(p);
	start(p);
}

void	is_already_sorted(t_p *p)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (i < p->size)
	{
		if (p->values[i] == p->sorted[i])
			j++;
		i++;
	}
	if (j == i)
		ft_exit(p, 0);
}

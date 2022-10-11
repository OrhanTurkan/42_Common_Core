/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oturkan <oturkan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 13:46:28 by oturkan           #+#    #+#             */
/*   Updated: 2022/07/13 11:05:18 by oturkan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int c, char **args)
{
	if (c < 2)
		exit(0);
	if (c >= 2)
	{
		if (is_digit_minus(c, args))
		{
			if (fail_detect(c, args))
			{
				find_values(c, args);
			}
		}
	}
	else
		ft_only_exit();
}

void	ft_exit(t_p *p, int a)
{
	if (p->values)
		free(p->values);
	if (p->sorted)
		free(p->sorted);
	if (p->a)
		free(p->a);
	if (p->b)
		free(p->b);
	if (p)
		free(p);
	if (a == 0)
		exit(0);
	else if (a == 1)
		ft_only_exit();
}

void	ft_only_exit(void)
{
	write(1, "ERROR\n", 6);
	exit(1);
}

void	index_it(t_p *p)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	p->a = (int *)malloc(sizeof(int) * p->size);
	if (!p->a)
		ft_exit(p, 0);
	while (i < p->size)
	{
		j = 0;
		while (j < p->size)
		{
			if (p->values[i] == p->sorted[j])
				p->a[i] = j;
			j++;
		}
		i++;
	}
}

void	max_bit_calculate(t_p *p)
{
	int	max;
	int	i;

	max = p->size - 1;
	i = 0;
	while (i < 32)
	{
		if ((max >> i) & 1)
			p->max_bit_size = i;
		i++;
	}
	p->max_bit_size++;
}

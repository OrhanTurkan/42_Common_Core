/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oturkan <oturkan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 11:17:15 by oturkan           #+#    #+#             */
/*   Updated: 2022/07/13 11:03:01 by oturkan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	start(t_p *p)
{
	index_it(p);
	max_bit_calculate(p);
	p->b = (int *)malloc(sizeof(int) * p->size);
	if (!p->b)
		ft_exit(p, 0);
	if (p->size == 2)
		ra(p);
	else if (p->size == 3)
		three_sort(p);
	else if (p->size == 4)
		four_sort(p);
	else if (p->size == 5)
		five_sort(p);
	else
	{
		sort(p);
	}
}

void	sort(t_p *p)
{
	int	i;
	int	bit;

	bit = 0;
	while (bit < p->max_bit_size)
	{
		i = 0;
		while (i < p->size)
		{
			if ((p->a[0] >> bit) & 1)
			{
				ra(p);
			}
			else
			{
				pb(p);
			}
			i++;
		}
		while (p->sizeb > 0)
		{
			pa(p);
		}
		bit++;
	}
}

void	three_sort(t_p *p)
{
	if ((p->a[1] > p->a[0]) && (p->a[1] > p->a[2]) \
		&& (p->a[0] < p->a[2]))
	{
		sa(p);
		ra(p);
	}
	else if ((p->a[1] > p->a[0]) && (p->a[1] > p->a[2]) \
		&& (p->a[0] > p->a[2]))
		rra(p);
	else if ((p->a[1] < p->a[0]) && (p->a[1] < p->a[2]) \
		&& (p->a[0] < p->a[2]))
		sa(p);
	else if ((p->a[1] < p->a[0]) && (p->a[1] > p->a[2]) \
		&& (p->a[0] > p->a[2]))
	{
		sa(p);
		rra(p);
	}
	else
		ra(p);
	if (p->b[0] < p->b[1])
		sb(p);
}

void	four_sort(t_p *p)
{
	int	pivot;
	int	i;

	i = p->sizea;
	pivot = average(p->a, p->sizea);
	while (i)
	{
		if (p->a[0] <= pivot)
			pb(p);
		else
			ra(p);
		i--;
	}
	if (p->sizea == 3 && p->sizeb > 0)
		three_sort(p);
	else if (p->sizeb == 3 && p->sizea > 0)
		three(p);
	else if (p->sizea == 2)
		two(p);
	while (p->sizeb)
		pa(p);
}

void	five_sort(t_p *p)
{
	int	pivot;
	int	i;

	i = p->sizea;
	pivot = average(p->a, p->sizea);
	while (i)
	{
		if (p->a[0] <= pivot)
			pb(p);
		else if (p->a[0] < p->a[1] \
			&& p->a[1] < p->a[2])
			break ;
		else
			ra(p);
		i--;
	}
	if (p->sizea == 3 && p->sizeb == 2)
		three_sort(p);
	else
		three(p);
	while (p->sizeb)
		pa(p);
}

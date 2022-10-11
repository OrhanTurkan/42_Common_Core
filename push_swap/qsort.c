/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   qsort.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oturkan <oturkan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 11:17:12 by oturkan           #+#    #+#             */
/*   Updated: 2022/07/04 20:18:05 by oturkan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	quick_sort(t_p *p, int first, int last)
{
	int	i;
	int	j;
	int	pivot;

	if (first < last)
	{
		pivot = first;
		i = first;
		j = last;
		while (i < j)
		{
			while (p->sorted[i] <= p->sorted[pivot] && i < last)
				i++;
			while (p->sorted[j] > p->sorted[pivot])
				j--;
			if (i < j)
				ft_swap(p, i, j);
		}
		ft_swap(p, pivot, j);
		quick_sort(p, first, j - 1);
		quick_sort(p, j + 1, last);
	}
}

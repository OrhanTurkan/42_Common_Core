/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubble.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oturkan <oturkan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 11:17:12 by oturkan           #+#    #+#             */
/*   Updated: 2022/07/13 11:05:56 by oturkan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	bubble_sort(t_p *p)
{
	int	i;
	int	j;

	i = 0;
	while (i < p->size)
	{
		j = 0;
		while (j < p->size - i - 1)
		{
			if (p->sorted[j] > p->sorted[j + 1])
				ft_swap(p, j, j + 1);
			j++;
		}
		i++;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_up_down.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oturkan <oturkan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 10:59:31 by oturkan           #+#    #+#             */
/*   Updated: 2022/07/13 11:06:07 by oturkan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	all_down(int *stack, int size)
{
	int	i;

	i = size - 1;
	while (i > 0)
	{
		stack[i] = stack[i - 1];
		i--;
	}
}

void	all_up(int *stack, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		stack[i] = stack[i + 1];
		i++;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oturkan <oturkan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 11:00:02 by oturkan           #+#    #+#             */
/*   Updated: 2022/07/13 11:04:48 by oturkan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_p *p)
{
	int	i;
	int	temp;

	if (p->sizea < 1)
		return ;
	i = p->sizea - 1;
	while (i > 0)
	{
		temp = p->a[i];
		p->a[i] = p->a[i - 1];
		p->a[i - 1] = temp;
		i--;
	}
	write(1, "rra\n", 4);
}

void	rrb(t_p *p)
{
	int	i;
	int	temp;

	if (p->sizeb < 1)
		return ;
	i = p->sizeb - 1;
	while (i > 0)
	{
		temp = p->b[i];
		p->b[i] = p->b[i - 1];
		p->b[i - 1] = temp;
		i--;
	}
	write(1, "rrb\n", 4);
}

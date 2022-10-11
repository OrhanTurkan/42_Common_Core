/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oturkan <oturkan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 11:00:05 by oturkan           #+#    #+#             */
/*   Updated: 2022/07/13 11:03:36 by oturkan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_p *p)
{
	int	temp;

	temp = p->a[0];
	all_up(p->a, p->size);
	p->a[p->sizea - 1] = temp;
	write(1, "ra\n", 3);
}

void	rb(t_p *p)
{
	int	temp;

	temp = p->b[0];
	all_up(p->b, p->size);
	p->b[p->sizeb - 1] = temp;
	write(1, "rb\n", 3);
}

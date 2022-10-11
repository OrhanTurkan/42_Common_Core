/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funcs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oturkan <oturkan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 11:16:59 by oturkan           #+#    #+#             */
/*   Updated: 2022/07/08 15:51:50 by oturkan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_p *p)
{
	all_down(p->a, p->size);
	p->a[0] = p->b[0];
	p->sizea++;
	all_up(p->b, p->size);
	p->sizeb--;
	write(1, "pa\n", 3);
}

void	pb(t_p *p)
{
	all_down(p->b, p->size);
	p->b[0] = p->a[0];
	p->sizeb++;
	all_up(p->a, p->size);
	p->sizea--;
	write(1, "pb\n", 3);
}

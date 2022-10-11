/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   values.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oturkan <oturkan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 11:17:21 by oturkan           #+#    #+#             */
/*   Updated: 2022/07/08 19:28:16 by oturkan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	find_values(int c, char **args)
{
	int		i;
	int		k;
	int		o;
	char	**temp;
	t_p		*p;

	i = 1;
	o = 0;
	k = 0;
	temp = 0;
	p = (t_p *)malloc(sizeof(t_p));
	if (!p)
		ft_exit(p, 0);
	split_count(c, args, p);
	p->values = (int *)malloc(sizeof(int) * p->size);
	p->size = 0;
	if (!p->values)
		ft_exit(p, 0);
	find_values2(c, args, temp, p);
	filled_struct(p);
}

void	find_values2(int c, char **args, char **temp, t_p *p)
{
	int	i;
	int	j;
	int	k;
	int	o;

	i = 1;
	k = 0;
	o = 0;
	while (i < c)
	{
		j = 0;
		temp = ft_split(args[i++], 32, p);
		while (temp[j])
			j++;
		k += j;
		j = 0;
		while (o < k)
			p->values[o++] = ft_atoi(p, temp[j++]);
		temp = 0;
	}
}

void	filled_struct(t_p *p)
{
	int	i;

	i = 0;
	p->sizea = p->size;
	p->sizeb = 0;
	p->sorted = (int *)malloc(sizeof(int) * p->size + 1);
	if (!p->sorted)
		ft_exit(p, 0);
	while (i < p->size)
	{
		p->sorted[i] = p->values[i];
		i++;
	}
	double_control(p);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oturkan <oturkan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 10:49:24 by oturkan           #+#    #+#             */
/*   Updated: 2022/07/14 10:53:07 by oturkan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	set_colors(t_f *f)
{
	if (f->i < f->it)
	{
		if (f->i < f->it / 2)
		{
			f->image_string[f->fi] = f->fi *(char)36;
			f->image_string[f->fi + 1] = f->i * (char)68;
			f->image_string[f->fi + 2] = (char)255;
		}
		else
		{
			f->image_string[f->fi] = (char)255;
			f->image_string[f->fi + 1] = f->fi * (char)36;
			f->image_string[f->fi + 2] = f->i * (char)68;
		}
	}
	else
	{
		f->image_string[f->fi] = 0;
		f->image_string[f->fi + 1] = 0;
		f->image_string[f->fi + 2] = 0;
	}
	f->fi += 4;
}

void	iterate(t_f *f, long double addx, long double addy)
{
	if (f->name == 'M' || f->name == 'B')
	{
		addx = f->manx;
		addy = f->many;
	}
	f->old_real = f->new_real;
	f->old_imag = f->new_imag;
	f->new_real = f->old_real * f->old_real - f->old_imag * f->old_imag + addx;
	f->new_imag = 2 * f->old_real * f->old_imag + addy;
	if (f->name == 'B')
	{
		f->new_real = ft_abs(f->new_real);
		f->new_imag = ft_abs(f->new_imag);
	}
}

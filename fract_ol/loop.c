/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oturkan <oturkan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 10:49:29 by oturkan           #+#    #+#             */
/*   Updated: 2022/07/14 10:54:45 by oturkan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	set_variables(t_f *f)
{
	f->manx = (f->x + (f->addx * f->z)) / (f->z * 1400 / 2);
	f->many = (f->y + (f->addy * f->z)) / (f->z * 800 / 2);
	f->new_real = f->manx;
	f->new_imag = f->many;
	if (f->name == 'B')
	{
		f->new_real = ft_abs(f->new_real);
		f->new_imag = ft_abs(f->new_imag);
	}
}

static void	start_image(t_f *f)
{
	f->image = mlx_new_image(f->mlx, 1400, 800);
	f->image_string = mlx_get_data_addr(f->image, &f->bpp, &f->sl, &f->endian);
	f->bpp = 0;
	f->sl = 0;
	f->endian = 0;
	f->fi = 0;
}

void	*loops(t_f *f)
{
	start_image(f);
	f->y = 800 / 2 * -1;
	while (f->y < 800 / 2)
	{
		f->x = 1400 / 2 * -1;
		while (f->x < 1400 / 2)
		{
			set_variables(f);
			f->i = 0;
			while (f->i < f->it && f->new_real * f->new_real \
					+ f->new_imag * f->new_imag < f->limit)
			{
				iterate(f, f->const_r, f->const_i);
				f->i++;
			}
			set_colors(f);
			f->x++;
		}
		f->y++;
	}
	mlx_put_image_to_window(f->mlx, f->win, f->image, 0, 0);
	return (0);
}

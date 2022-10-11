/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   user.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oturkan <oturkan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 10:49:21 by oturkan           #+#    #+#             */
/*   Updated: 2022/07/16 12:00:10 by oturkan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	key_press(int key, t_f *f)
{
	if (key == 53)
		exit(1);
	if (key == 123)
		f->addx += 10 / f->z;
	if (key == 124)
		f->addx -= 10 / f->z;
	if (key == 126)
		f->addy += 10 / f->z;
	if (key == 125)
		f->addy -= 10 / f->z;
	if (key == 24 && f->it < 1000)
		f->it += 100;
	if (key == 27 && f->it > 100)
		f->it -= 100;
	if (key == 29)
		set_it(f);
	mlx_clear_window(f->mlx, f->win);
	loops(f);
	return (0);
}

int	closing(void *param)
{
	(void)param;
	exit(0);
	return (0);
}

int	mouse_move(int x, int y, t_f *f)
{
	if (x > 0 && x < 1400 && y > 0 && y < 800 && f->click)
	{
		f->const_r = 0.95 * x / 1400 + 1;
		if (f->const_r > 1)
			f->const_r -= 2;
		else if (f->const_r < -1)
			f->const_r += 2;
		f->const_i = 0.95 * y / 800 + 1;
		if (f->const_i > 1)
			f->const_i -= 2;
		else if (f->const_i < -1)
			f->const_i += 2;
		mlx_clear_window(f->mlx, f->win);
		loops(f);
	}
	return (0);
}

int	mouse_press(int button, int x, int y, t_f *f)
{
	if (button == 1)
	{
		if (f->click == 1)
			f->click = 0;
		else
			f->click = 1;
	}
	if (button == 4)
		f->z /= 1.5;
	if (button == 5)
	{
		f->z *= 1.5;
		f->addx += (x - 1400 / 2) / f->z / 2;
		f->addy += (y - 800 / 2) / f->z / 2;
	}
	if (f->z < 0.05)
		f->z *= 1.5;
	mlx_clear_window(f->mlx, f->win);
	loops(f);
	return (0);
}

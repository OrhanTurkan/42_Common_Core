/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oturkan <oturkan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 10:49:38 by oturkan           #+#    #+#             */
/*   Updated: 2022/07/14 10:49:38 by oturkan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int c, char **args)
{
	if (c != 2)
	{
		write(1, "!!!\n", 4);
		write(1, "Options :\n1- (M) Mandelbrot\n2- (J)Julia\n", 41);
		write(1, "3- (B)Burningship\n", 18);
		return (0);
	}
	if (ft_strcmp(args[1], "Julia") && ft_strcmp(args[1], "Mandelbrot") \
			&& ft_strcmp(args[1], "Burningship"))
	{
		write(1, "Wrong!!!\n", 9);
		write(1, "Options :\n1- (M) Mandelbrot\n2- (J)Julia\n", 41);
		write(1, "3- (B)Burningship\n", 18);
	}
	else
		start(args[1]);
	return (0);
}

void	start(char *name)
{
	t_f	*f;

	f = 0;
	while (!f)
		f = (t_f *)malloc(sizeof(t_f));
	f->name = name[0];
	f->mlx = mlx_init();
	if (f->name == 'J')
		f->win = mlx_new_window(f->mlx, 1400, 800, \
			"Julia Fract-ol by Oturkan");
	else if (f->name == 'M')
		f->win = mlx_new_window(f->mlx, 1400, 800, \
			"Mandelbrot Fract-ol by Oturkan");
	else if (f->name == 'B')
		f->win = mlx_new_window(f->mlx, 1400, 800, \
			"Burningship Fract-ol by Oturkan");
	set_it(f);
	window(f);
}

void	set_it(t_f *f)
{
	f->click = 1;
	f->addx = 0;
	f->addy = 0;
	f->it = 100;
	f->limit = 10;
	f->const_r = -0.835;
	f->const_i = 0.2321;
	f->z = 0.5;
}

void	window(t_f *f)
{
	mlx_hook(f->win, 2, 2, key_press, f);
	mlx_hook(f->win, 17, 17, closing, 0);
	mlx_hook(f->win, 4, 4, mouse_press, f);
	if (f->name == 'J')
		mlx_hook(f->win, 6, 6, mouse_move, f);
	loops(f);
	mlx_loop(f->mlx);
}

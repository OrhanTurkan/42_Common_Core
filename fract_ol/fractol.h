/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oturkan <oturkan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 10:49:32 by oturkan           #+#    #+#             */
/*   Updated: 2022/07/14 10:49:32 by oturkan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include <stdlib.h>
# include <math.h>
# include <unistd.h>
# include "mlx/mlx.h"

typedef struct s_f
{
	int					fi;
	int					i;
	int					x;
	int					y;
	int					it;
	short				limit;
	long double			addx;
	long double			addy;
	long double			new_real;
	long double			new_imag;
	long double			old_real;
	long double			old_imag;
	long double			const_r;
	long double			const_i;
	long double			manx;
	long double			many;
	long double			z;
	int					click;
	void				*image;
	char				*image_string;
	void				*mlx;
	void				*win;
	char				name;
	int					bpp;
	int					sl;
	int					endian;
}				t_f;

int				ft_strcmp(const char *s1, const char *s2);
void			start(char *name);
void			window(t_f *f);
void			set_it(t_f *f);
void			set_colors(t_f *f);
void			iterate(t_f *f, long double addx, long double addy);
long double		ft_abs(long double c);
void			*loops(t_f *f);
int				key_press(int key, t_f *f);
int				closing(void *param);
int				mouse_press(int button, int x, int y, t_f *f);
int				mouse_move(int x, int y, t_f *f);
void			*loops(t_f *f);

#endif

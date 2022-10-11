/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oturkan <oturkan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 13:46:22 by oturkan           #+#    #+#             */
/*   Updated: 2022/07/13 11:05:05 by oturkan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <string.h>
# include <unistd.h>
# include <fcntl.h>

typedef struct s_p
{
	int	*values;
	int	*sorted;
	int	*a;
	int	*b;
	int	sizea;
	int	sizeb;
	int	size;
	int	max_bit_size;
}				t_p;

size_t	ft_strlen(const char *s);
int		average(int *stack, int size);
void	max_bit_calculate(t_p *p);
void	ft_swap(t_p *p, int a, int b);
void	is_already_sorted(t_p *p);
void	bubble_sort(t_p *p);
void	ft_exit(t_p *p, int a);
void	ft_only_exit(void);
void	filled_struct(t_p *p);
void	split_count(int c, char **args, t_p *p);
int		ft_atoi(t_p *p, const char *nptr);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
int		is_digit_minus(int c, char **args);
int		fail_detect(int c, char **args);
int		fail_detect2(int c, char **args);
void	find_values(int c, char **args);
void	find_values2(int c, char **args, char **temp, t_p *p);
char	**ft_split(char const *s, char c, t_p *p);
void	double_control(t_p *p);
void	three(t_p *p);
void	two(t_p *p);
void	three_sort(t_p *p);
void	four_sort(t_p *p);
void	five_sort(t_p *p);
void	start(t_p *p);
void	index_it(t_p *p);
void	sort(t_p *p);
void	all_down(int *stack, int size);
void	all_up(int *stack, int size);
void	pa(t_p *p);
void	pb(t_p *p);
void	ra(t_p *p);
void	rb(t_p *p);
void	sa(t_p *p);
void	sb(t_p *p);
void	rra(t_p *p);
void	rrb(t_p *p);

#endif

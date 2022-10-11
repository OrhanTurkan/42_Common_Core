/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oturkan <oturkan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 14:19:34 by oturkan           #+#    #+#             */
/*   Updated: 2022/09/24 15:49:58 by oturkan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <sys/time.h>
# include <stdio.h>
# include <unistd.h>
# include <pthread.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_philo
{
	int					id;
	int					ate_count;
	pthread_t			th;
	pthread_mutex_t		fork;
	pthread_mutex_t		*left_fork;
	unsigned long long	start_time;
	unsigned long long	last_eat_time;
	struct s_data		*data;
}				t_philo;

typedef struct s_data
{
	int					number_of_philo;
	unsigned long long	time_to_die;
	unsigned long long	time_to_eat;
	unsigned long long	time_to_sleep;
	int					number_of_eat;
	int					is_dead;
	pthread_mutex_t		time_lock;
	pthread_mutex_t		print_lock;
	pthread_mutex_t		died_lock;
	t_philo				philo[200];
}				t_data;

int					ft_atoi(const char *nptr);
int					is_num(char **args, int argc);
int					philo_init(t_data *data);
int					destroy_mutex(t_data *data);
int					join_thread(t_data *data, pthread_t *angel);
int					create_thread(t_data *data, pthread_t *angel);
void				*control_alive(void *v_arg);
void				*create_philo(void *v_philo);
void				*control_alive(void *v_arg);
void				eating_philo(t_philo *philo);
void				sleeping_philo(t_philo *philo, int i);
void				print_status(t_philo *philo, unsigned long long \
time, char *verb);
unsigned long long	get_milisec(void);

#endif
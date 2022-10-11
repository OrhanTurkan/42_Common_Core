/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat_sleep_die.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oturkan <oturkan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 18:05:25 by oturkan           #+#    #+#             */
/*   Updated: 2022/09/24 14:58:11 by oturkan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_status(t_philo *philo, unsigned long long time, char *verb)
{
	pthread_mutex_lock(&(philo->data->print_lock));
	pthread_mutex_lock(&(philo->data->died_lock));
	if (!philo->data->is_dead)
		printf("%llu\t%d\t%s\n", get_milisec() - time, philo->id, verb);
	pthread_mutex_unlock(&(philo->data->print_lock));
	pthread_mutex_unlock(&(philo->data->died_lock));
}

void	sleeping_philo(t_philo *philo, int i)
{
	unsigned long long	start_time;

	if (i == 1)
	{
		while (get_milisec() - philo->last_eat_time <= philo->data->time_to_eat)
			usleep(100);
	}
	else
	{
		start_time = get_milisec();
		while (get_milisec() - start_time <= philo->data->time_to_sleep)
			usleep(100);
	}
}

void	eating_philo(t_philo *philo)
{
	pthread_mutex_lock(philo->left_fork);
	print_status(philo, philo->start_time, " has taken a fork.");
	pthread_mutex_lock(&(philo->fork));
	print_status(philo, philo->start_time, " has taken a fork.");
	print_status(philo, philo->start_time, " is eating.");
	pthread_mutex_lock(&(philo->data->time_lock));
	philo->last_eat_time = get_milisec();
	pthread_mutex_unlock(&(philo->data->time_lock));
	sleeping_philo(philo, 1);
	pthread_mutex_lock(&(philo->data->died_lock));
	(philo->ate_count)++;
	pthread_mutex_unlock(&(philo->data->died_lock));
	pthread_mutex_unlock(&(philo->fork));
	pthread_mutex_unlock(philo->left_fork);
}

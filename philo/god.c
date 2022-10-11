/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   god.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oturkan <oturkan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 14:34:08 by oturkan           #+#    #+#             */
/*   Updated: 2022/09/22 17:15:44 by oturkan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	philo_init(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->number_of_philo)
	{
		data->philo[i].start_time = get_milisec();
		data->philo[i].id = i + 1;
		data->philo[i].data = data;
		data->philo[i].ate_count = 0;
		if (i == 0)
			data->philo[i].left_fork = \
			&(data->philo[data->number_of_philo - 1].fork);
		else
			data->philo[i].left_fork = &(data->philo[i - 1].fork);
		if (pthread_mutex_init(&(data->philo[i].fork), NULL))
			return (1);
		i++;
	}
	return (0);
}

int	create_thread(t_data *data, pthread_t *angel)
{
	int	i;

	i = 0;
	while (i < data->number_of_philo)
	{
		data->philo[i].last_eat_time = get_milisec();
		if (pthread_create(&(data->philo[i].th), NULL, \
			create_philo, &(data->philo[i])))
			return (1);
		i++;
	}
	if (pthread_create(angel, NULL, control_alive, data))
		return (1);
	return (0);
}

int	join_thread(t_data *data, pthread_t *angel)
{
	int	i;

	i = 0;
	while (i < data->number_of_philo)
	{
		if (pthread_join(data->philo[i].th, NULL))
			return (1);
		i++;
	}
	if (pthread_join(*angel, NULL))
		return (1);
	return (0);
}

int	destroy_mutex(t_data *data)
{
	int	i;

	i = 0;
	if (pthread_mutex_destroy(&(data->died_lock)) || \
	pthread_mutex_destroy(&(data->print_lock)) || \
	pthread_mutex_destroy(&(data->time_lock)))
		return (1);
	while (data->number_of_philo > i)
	{
		if (pthread_mutex_destroy(&(data->philo[i].fork)))
			return (1);
		i++;
	}
	return (0);
}

void	*create_philo(void *v_philo)
{
	t_philo	*philo;

	philo = (t_philo *)v_philo;
	if (!(philo->id % 2))
		usleep(1000);
	while (1)
	{
		eating_philo(philo);
		print_status(philo, philo->start_time, " is sleeping.");
		sleeping_philo(philo, 0);
		print_status(philo, philo->start_time, " is thinking.");
		pthread_mutex_lock(&(philo->data->died_lock));
		if (philo->data->is_dead || (philo->data->number_of_eat != -1 && \
			philo->ate_count == philo->data->number_of_eat))
		{
			pthread_mutex_unlock(&(philo->data->died_lock));
			break ;
		}
		else
			pthread_mutex_unlock(&(philo->data->died_lock));
	}
	return (NULL);
}

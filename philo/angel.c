/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   angel.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oturkan <oturkan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 15:13:45 by oturkan           #+#    #+#             */
/*   Updated: 2022/09/24 14:58:19 by oturkan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	control_alive_2(t_philo *philo, t_data *data)
{
	static int	printable = 1;

	pthread_mutex_lock(&(data->time_lock));
	if (get_milisec() - philo->last_eat_time >= data->time_to_die)
	{
		pthread_mutex_unlock(&(data->time_lock));
		pthread_mutex_lock(&(data->died_lock));
		data->is_dead = 1;
		pthread_mutex_unlock(&(data->died_lock));
		if (printable)
		{
			printf("%llu\t%d\t%s\n", get_milisec() - philo->start_time, \
			philo->id, " is died.");
			printable = 0;
		}
	}
	else
		pthread_mutex_unlock(&(data->time_lock));
}

void	*control_alive(void *v_arg)
{
	int			i;
	t_data		*data;

	data = (t_data *)v_arg;
	i = 0;
	while (!(data->is_dead))
	{
		if (i == data->number_of_philo)
			i = 0;
		control_alive_2(&(data->philo[i]), data);
		pthread_mutex_lock(&(data->died_lock));
		if (data->number_of_eat != -1 && \
			(data->philo[i].ate_count == data->number_of_eat))
		{
			pthread_mutex_unlock(&(data->died_lock));
			break ;
		}
		pthread_mutex_unlock(&(data->died_lock));
		i++;
	}
	return (NULL);
}

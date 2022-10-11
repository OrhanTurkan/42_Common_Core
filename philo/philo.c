/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oturkan <oturkan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 14:19:31 by oturkan           #+#    #+#             */
/*   Updated: 2022/09/24 15:50:02 by oturkan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	start(t_data *data)
{
	pthread_t	angel;

	if (data->number_of_philo == 1)
	{
		printf("0\t1 has taken a fork.\n");
		usleep(data->time_to_die * 1000);
		printf("%llu\t1 is died\n", data->time_to_die);
		return (0);
	}
	if (data->number_of_philo > 200 || data->number_of_philo < 2 \
		|| data->number_of_eat == 0 || data->time_to_die == 0)
		return (1);
	if (philo_init(data) || create_thread(data, &angel) \
		|| join_thread(data, &angel) || destroy_mutex(data))
		return (1);
	return (0);
}

int	main(int argc, char **args)
{
	t_data	data;

	if ((argc == 5 || argc == 6) && is_num(args, argc))
	{	
		data.number_of_philo = ft_atoi(args[1]);
		data.time_to_die = ft_atoi(args[2]);
		data.time_to_eat = ft_atoi(args[3]);
		data.time_to_sleep = ft_atoi(args[4]);
		data.number_of_eat = -1;
	}
	else
		return (1);
	if (argc == 6)
		data.number_of_eat = ft_atoi(args[5]);
	data.is_dead = 0;
	if (pthread_mutex_init(&(data.time_lock), NULL))
		return (1);
	if (pthread_mutex_init(&(data.died_lock), NULL))
		return (1);
	if (pthread_mutex_init(&(data.print_lock), NULL))
		return (1);
	return (start(&data));
}

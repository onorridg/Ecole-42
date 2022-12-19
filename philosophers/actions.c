/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onorridg <onorridg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 14:53:52 by onorridg          #+#    #+#             */
/*   Updated: 2022/03/27 14:30:55 by onorridg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_think(t_philo *data)
{	
	struct timeval		tv2;
	unsigned long long	two;

	gettimeofday(&tv2, NULL);
	two = (tv2.tv_sec) * 1000 + (tv2.tv_usec) / 1000;
	printf("%lli %lli is thinking\n", two - data->start, data->number);
}

static int	my_mutex_lock(t_philo *data, int fork)
{
	pthread_t	thread_time;

	data->mutex_while = 0;
	if (pthread_create(&thread_time, NULL, check_fck_time, data))
	{
		printf("[!] Error pthread create\n");
		return (1);
	}
	pthread_detach(thread_time);
	if (pthread_mutex_lock(&data->mutex_forks[fork]))
	{
		printf("[!] Error mutex lock\n");
		return (1);
	}
	data->mutex_while = 1;
	return (0);
}

static int	take_foks(t_philo *data)
{
	if (my_mutex_lock(data, data->fork1))
		return (1);
	if (check_die(data))
	{
		pthread_mutex_unlock(&data->mutex_forks[data->fork1]);
		return (1);
	}
	data->two = my_gettimeofday();
	printf("%lli %lli has taken a fork\n", data->two - data->start,
		data->number);
	if (my_mutex_lock(data, data->fork2))
		return (1);
	if (check_die(data))
	{
		pthread_mutex_unlock(&data->mutex_forks[data->number]);
		pthread_mutex_unlock(&data->mutex_forks[data->fork2]);
		return (1);
	}
	data->two = my_gettimeofday();
	printf("%lli %lli has taken a fork\n", data->two - data->start,
		data->number);
	return (0);
}

int	eating(t_philo *data)
{
	if (take_foks(data))
		return (1);
	printf("%lli %lli is eating\n", data->two - data->start,
		data->number);
	my_usleep(data->ph_info->t_eat,
		data->ph_info->t_die - (data->two - data->one));
	if (check_die(data))
	{
		pthread_mutex_unlock(&data->mutex_forks[data->number]);
		pthread_mutex_unlock(&data->mutex_forks[data->fork2]);
		return (1);
	}
	pthread_mutex_unlock(&data->mutex_forks[data->number]);
	pthread_mutex_unlock(&data->mutex_forks[data->fork2]);
	if (check_die(data))
		return (1);
	return (0);
}

int	sleeping(t_philo *data)
{
	data->one = my_gettimeofday();
	data->two = my_gettimeofday();
	printf("%lli %lli is sleeping\n", data->two - data->start, data->number);
	my_usleep(data->ph_info->t_sleep,
		data->ph_info->t_die - (data->two - data->one));
	if (check_die(data))
		return (1);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onorridg <onorridg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 16:32:31 by onorridg          #+#    #+#             */
/*   Updated: 2022/03/27 14:09:25 by onorridg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

pthread_mutex_t	*mutex_forks(int n_philo)
{	
	pthread_mutex_t	*mutex_forks_arr;
	int				i;

	mutex_forks_arr = (pthread_mutex_t *)malloc(
			sizeof(pthread_mutex_t) * n_philo + 1);
	i = 0;
	while (i < n_philo)
	{
		if (pthread_mutex_init(&mutex_forks_arr[i++], NULL))
			return (0);
	}
	return (mutex_forks_arr);
}

int	check_die(t_philo *data)
{	
	struct timeval		tv2;
	long long			two;

	if (*data->die == 1)
		return (1);
	gettimeofday(&tv2, NULL);
	two = (tv2.tv_sec) * 1000 + (tv2.tv_usec) / 1000;
	if (two - data->one >= data->ph_info->t_die)
	{
		*data->die = 1;
		printf("%llu %llu died\n", two - data->start, data->number);
		return (1);
	}
	return (0);
}

int	start_thread(t_philo *data)
{	
	data->fork1 = data->number;
	if (data->number == data->ph_info->phil - 1)
		data->fork2 = 0;
	else
		data->fork2 = data->number + 1;
	data->one = my_gettimeofday();
	data->start = data->one;
	if (data->number % 2 != 0)
		usleep(1000);
	return (0);
}

long long	my_gettimeofday(void)
{
	struct timeval	tv1;

	gettimeofday(&tv1, NULL);
	return ((tv1.tv_sec) * 1000 + (tv1.tv_usec) / 1000);
}

int	my_usleep(long long sleep_time, long long kek)
{
	struct timeval	tv1;
	struct timeval	tv2;
	long long		one;
	long long		two;

	gettimeofday(&tv1, NULL);
	one = (tv1.tv_sec) * 1000 + (tv1.tv_usec) / 1000;
	two = (tv1.tv_sec) * 1000 + (tv1.tv_usec) / 1000;
	while (two - one < sleep_time)
	{
		gettimeofday(&tv2, NULL);
		two = (tv2.tv_sec) * 1000 + (tv2.tv_usec) / 1000;
		if (two - one >= kek)
			return (1);
		usleep(10);
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onorridg <onorridg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 17:29:13 by onorridg          #+#    #+#             */
/*   Updated: 2022/03/27 14:06:33 by onorridg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*check_fck_time(void *d)
{	
	t_philo	*data;

	data = (t_philo *)d;
	while (data->mutex_while != 1)
	{
		if (check_die(data))
		{	
			*data->die = 1;
			pthread_mutex_unlock(&data->mutex_forks[data->fork1]);
			if (data->mutex_unlock_n == 2 || data->ph_info->phil == 1)
				pthread_mutex_unlock(&data->mutex_forks[data->fork2]);
			return (0);
		}
		usleep(10);
	}
	return (NULL);
}

void	*thread_func(void *d)
{	
	t_philo	*data;

	data = (t_philo *)d;
	if (start_thread(data) == 1)
		return (0);
	while (*data->die != 1 && data->eat != 0)
	{
		if (data->eat != -1)
			data->eat -= 1;
		if (eating(data))
			return (NULL);
		if (sleeping(data))
			return (NULL);
		ft_think(data);
	}
	return (NULL);
}

static int	phil(t_philo_info *ph, int i, long long die)
{
	pthread_t		*thread_arr;
	t_philo			*philo;
	pthread_mutex_t	*mutex_forks_arr;

	mutex_forks_arr = mutex_forks(ph->phil);
	if (!mutex_forks_arr)
		return (exit_error(NULL, "[!] Error mutex arr", NULL, 0));
	philo = create_philo_arr(ph, &die, mutex_forks_arr);
	if (!philo)
	{
		free(mutex_forks_arr);
		return (exit_error(NULL, "[!] Error malloc", NULL, 0));
	}
	thread_arr = get_thread_arr(ph->phil);
	if (!thread_arr)
		return (exit_error(thread_arr, "[!] Error malloc", &philo, 0));
	while (i < ph->phil)
	{
		if (pthread_create(&thread_arr[i], NULL, thread_func, &philo[i]))
			return (exit_error(thread_arr,
					"[!] Error thread create", &philo, 0));
		i++;
	}
	return (exit_success(thread_arr, 0, &philo));
}

int	main(int ac, char **av)
{	
	t_philo_info	ph;

	if ((ac != 5 && ac != 6) || !data_validation(ac, av)
		|| !set_data(ac, av, &ph))
		return (exit_error(NULL, "[!] Your args so shit", NULL, 0));
	return (phil(&ph, 0, 0));
}

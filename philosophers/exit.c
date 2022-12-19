/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onorridg <onorridg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 13:10:59 by onorridg          #+#    #+#             */
/*   Updated: 2022/03/27 14:09:01 by onorridg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	exit_success(pthread_t *pthread_arr, int i, t_philo	**philo)
{
	while (i < philo[0]->ph_info->phil)
	{
		if (pthread_join(pthread_arr[i], NULL))
			return (exit_error(NULL, "[!] Error thread join", NULL, 0));
		i++;
	}
	free(pthread_arr);
	i = 0;
	while (i < philo[0]->ph_info->phil)
	{
		if (pthread_mutex_destroy(&philo[0]->mutex_forks[i]))
			return (exit_error(NULL, "[!] Error mutex destroy", NULL, 0));
		i++;
	}
	free(philo[0]->mutex_forks);
	free(*philo);
	return (0);
}

int	exit_error(pthread_t *pthread_arr, char *err, t_philo **philo, long long i)
{	
	printf("%s\n", err);
	if (philo && pthread_arr)
	{
		while (i < philo[0]->ph_info->phil)
		{
			if (pthread_join(pthread_arr[i++], NULL))
				return (-1);
		}
		free(pthread_arr);
	}
	i = 0;
	if (philo)
	{
		while (i < philo[0]->ph_info->phil)
		{
			if (pthread_mutex_destroy(&philo[0]->mutex_forks[i++]))
				return (-1);
		}
		free(philo[0]->mutex_forks);
		free(*philo);
	}
	return (-1);
}

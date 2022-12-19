/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onorridg <onorridg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 18:06:06 by onorridg          #+#    #+#             */
/*   Updated: 2022/03/25 19:10:44 by onorridg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_philo	*create_philo_arr(t_philo_info *philo_info, long long *die,
	pthread_mutex_t *mutex_forks)
{	
	int		i;
	t_philo	*p;

	i = 0;
	p = (t_philo *)malloc(sizeof(t_philo) * philo_info->phil + 1);
	if (!p)
		return (0);
	i = 0;
	while (i < philo_info->phil)
	{
		p[i].number = i;
		p[i].ph_info = philo_info;
		p[i].die = die;
		p[i].mutex_forks = mutex_forks;
		p[i].eat = philo_info->num_t_ph_must_eat;
		i++;
	}
	return (p);
}

pthread_t	*get_thread_arr(int count)
{	
	pthread_t	*thread_arr;

	thread_arr = (pthread_t *)malloc(sizeof(pthread_t) * count);
	if (!thread_arr)
		return (0);
	return (thread_arr);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	num;

	i = 0;
	while (str[i] == '\n' || str[i] == '\t' || str[i] == '\v'
		|| str[i] == '\r' || str[i] == '\f' || str[i] == ' ')
		i++;
	if (str[i] < '0' || str[i] > '9')
		return (-1);
	num = 0;
	while (str[i] >= '0' && str[i] <= '9')
		num = num * 10 + (str[i++] - '0');
	return (num);
}

int	data_validation(int ac, char **av)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		if (ft_atoi(av[i++]) == -1)
			return (0);
	}
	return (1);
}

int	set_data(int ac, char **av, t_philo_info *ph)
{
	ph->phil = ft_atoi(av[1]);
	if (ph->phil <= 0)
		return (0);
	ph->t_die = ft_atoi(av[2]);
	ph->t_eat = ft_atoi(av[3]);
	ph->t_sleep = ft_atoi(av[4]);
	if (ac == 6)
		ph->num_t_ph_must_eat = ft_atoi(av[5]);
	else
		ph->num_t_ph_must_eat = -1;
	return (1);
}

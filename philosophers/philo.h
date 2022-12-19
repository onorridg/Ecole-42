/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onorridg <onorridg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 17:29:10 by onorridg          #+#    #+#             */
/*   Updated: 2022/03/27 14:06:10 by onorridg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# define TRUE 1
# define FALSE 0

# define MILLISECOND 1000
# define SECOND 1000000

# include <string.h> /* memset, */
# include <stdio.h>	/* printf, */
# include <stdlib.h> /* malloc, free */
# include <unistd.h> /* write, usleep, */
# include <sys/time.h> /* gettimeofday, */
# include <pthread.h> /* pthread_create, pthread_detach, pt* ... */

# define RED   "\x1B[31m"
# define GRN   "\x1B[32m"
# define YEL   "\x1B[33m"
# define BLU   "\x1B[34m"
# define MAG   "\x1B[35m"
# define CYN   "\x1B[36m"
# define WHT   "\x1B[37m"
# define RESET "\x1B[0m"

typedef struct s_philo_info
{
	long long	phil;
	long long	t_die;
	long long	t_eat;
	long long	t_sleep;
	long long	num_t_ph_must_eat;
}	t_philo_info;

typedef struct s_philo
{
	long long		number;
	t_philo_info	*ph_info;
	long long		*die;
	pthread_mutex_t	*mutex_forks;
	long long		eat;
	long long		start;
	long long		one;
	long long		two;
	int				fork2;
	int				fork1;
	int				mutex_unlock_n;
	int				mutex_while;
}	t_philo;

int					data_validation(int ac, char **av);
int					set_data(int ac, char **av, t_philo_info *ph);
int					ft_atoi(const char *str);
int					exit_error(pthread_t *pthread_arr, char *err,
						t_philo **data, long long i);
int					exit_success(pthread_t *pthread_arr, int i,
						t_philo	**philo);
pthread_t			*get_thread_arr(int count);
t_philo				*create_philo_arr(t_philo_info *philo_info,
						long long *die, pthread_mutex_t *mutex_forks);
int					my_usleep(long long sleep_time, long long kek);
long long			my_gettimeofday(void);
int					start_thread(t_philo *data);
int					check_die(t_philo *data);
pthread_mutex_t		*mutex_forks(int n_philo);
void				*check_fck_time(void *d);
void				ft_think(t_philo *data);
int					eating(t_philo *data);
int					sleeping(t_philo *data);
#endif

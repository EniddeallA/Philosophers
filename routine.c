/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhalid <akhalid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 06:40:55 by akhalid           #+#    #+#             */
/*   Updated: 2021/11/16 01:38:11 by akhalid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	getting_forks(t_philo *philo)
{
	int	pos;

	pos = philo->id - 1;
	pthread_mutex_lock(&philo->args->forks);
	pthread_mutex_lock(&philo->args->fork[pos]);
	pthread_mutex_lock(&philo->args->print);
	printf("%ld %d has taken a fork\n", get_time_ms(philo->args->start_time),
		philo->id);
	pthread_mutex_unlock(&philo->args->print);
	pthread_mutex_lock(&philo->args->fork[(pos + 1) % philo->args->n_philo]);
	pthread_mutex_lock(&philo->args->print);
	printf("%ld %d has taken a fork\n", get_time_ms(philo->args->start_time),
		philo->id);
	pthread_mutex_unlock(&philo->args->print);
	pthread_mutex_unlock(&philo->args->forks);
}

void	eating(t_philo *philo)
{
	int	pos;

	pos = philo->id - 1;
	philo->status = EATING;
	pthread_mutex_lock(&philo->eat);
	pthread_mutex_lock(&philo->args->print);
	printf("%ld %d is eating\n", get_time_ms(philo->args->start_time),
		philo->id);
	pthread_mutex_unlock(&philo->args->print);
	pthread_mutex_unlock(&philo->args->fork[pos]);
	pthread_mutex_unlock(&philo->args->fork[(pos + 1) % philo->args->n_philo]);
	pthread_mutex_unlock(&philo->eat);
	philo->last_eat = get_time_ms(0);
	my_usleep(philo->args->eat_time);
}

void	sleeping(t_philo *philo)
{
	philo->status = SLEEPING;
	pthread_mutex_lock(&philo->args->print);
	printf("%ld %d is sleeping\n", get_time_ms(philo->args->start_time),
		philo->id);
	pthread_mutex_unlock(&philo->args->print);
	my_usleep(philo->args->sleep_time);
}

void	thinking(t_philo *philo)
{
	philo->status = THINKING;
	pthread_mutex_lock(&philo->args->print);
	printf("%ld %d is thinking\n", get_time_ms(philo->args->start_time),
		philo->id);
	pthread_mutex_unlock(&philo->args->print);
}

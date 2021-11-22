/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhalid <akhalid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 06:40:55 by akhalid           #+#    #+#             */
/*   Updated: 2021/11/22 18:25:47 by akhalid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	getting_forks(t_philo *philo)
{
	int	pos;

	pos = philo->id - 1;
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
}

void	eating(t_philo *philo)
{
	int	pos;

	pos = philo->id - 1;
	pthread_mutex_lock(&philo->eat);
	pthread_mutex_lock(&philo->args->print);
	printf("%ld %d is eating\n", get_time_ms(philo->args->start_time),
		philo->id);
	pthread_mutex_unlock(&philo->args->print);
	philo->total_eat += 1;
	philo->last_eat = get_time_ms(philo->args->start_time);
	my_usleep(philo->args->eat_time);
	pthread_mutex_unlock(&philo->args->fork[pos]);
	pthread_mutex_unlock(&philo->args->fork[(pos + 1) % philo->args->n_philo]);
	pthread_mutex_unlock(&philo->eat);
}

void	sleeping(t_philo *philo)
{
	pthread_mutex_lock(&philo->args->print);
	printf("%ld %d is sleeping\n", get_time_ms(philo->args->start_time),
		philo->id);
	pthread_mutex_unlock(&philo->args->print);
	my_usleep(philo->args->sleep_time);
}

void	thinking(t_philo *philo)
{
	pthread_mutex_lock(&philo->args->print);
	printf("%ld %d is thinking\n", get_time_ms(philo->args->start_time),
		philo->id);
	pthread_mutex_unlock(&philo->args->print);
}

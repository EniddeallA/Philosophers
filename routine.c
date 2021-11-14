/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhalid <akhalid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 06:40:55 by akhalid           #+#    #+#             */
/*   Updated: 2021/11/14 08:56:30 by akhalid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	getting_forks(t_philo *philo)
{
	int	pos;

	pos = philo->id - 1;
	pthread_mutex_lock(&philo->args->fork[pos]);
	pthread_mutex_lock(&philo->args->fork[(pos + 1) % philo->args->n_philo]);
	pthread_mutex_lock(&philo->args->print);
	printf("timestamp_in_ms %d has taken a fork\n", philo->id);
	pthread_mutex_unlock(&philo->args->print);
}

void	eating(t_philo *philo)
{
	int	pos;

	pos = philo->id - 1;
	philo->status = EATING;
	pthread_mutex_lock(&philo->eat);
	pthread_mutex_lock(&philo->args->print);
	printf("timestamp_in_ms %d is eating\n", philo->id);
	pthread_mutex_unlock(&philo->args->print);
	pthread_mutex_unlock(&philo->args->fork[pos]);
	pthread_mutex_unlock(&philo->args->fork[(pos + 1) % philo->args->n_philo]);
	pthread_mutex_unlock(&philo->eat);
}

void	sleeping(t_philo *philo)
{
	philo->status = SLEEPING;
	pthread_mutex_lock(&philo->args->print);
	printf("timestamp_in_ms %d is sleeping\n", philo->id);
	pthread_mutex_unlock(&philo->args->print);
}

void	thinking(t_philo *philo)
{
	philo->status = THINKING;
	pthread_mutex_lock(&philo->args->print);
	printf("timestamp_in_ms %d is thinking\n", philo->id);
	pthread_mutex_unlock(&philo->args->print);
}

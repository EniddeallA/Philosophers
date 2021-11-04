/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eniddealla <eniddealla@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 08:05:33 by akhalid           #+#    #+#             */
/*   Updated: 2021/11/04 15:08:20 by eniddealla       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	output(long time, t_philo *philo, char *msg)
{
	int			id;
	uint64_t	tm;

	id = philo->p_id + 1;
	tm = time - philo->args->time;
	printf ("%llu Philosopher %d\n", tm, id, msg);
}

void fork(t_philo *philo)
{
    int					left;
	int					right;

	right = (philo->p_id + 1) % philo->args->n_philo;
	left = philo->p_id;
	if ((philo->p_id + 1) % 2 == 0)
	{
		pthread_mutex_lock(&philo->args->forks[right]);
		pthread_mutex_lock(&philo->args->forks[left]);
	}
	else
	{
		pthread_mutex_lock(&philo->args->forks[left]);
		pthread_mutex_lock(&philo->args->forks[right]);
	}
	pthread_mutex_lock(&philo->args->print);
    // Taken a fork
    output(get_timestamp(), philo, "Taken a fork");
	pthread_mutex_unlock(&philo->args->print);
}

void eat(t_philo *philo)
{
    int	right;
	int	left;

	right = (philo->p_id + 1) % philo->args->n_philo;
	left = philo->p_id;
	philo->status = EATING;
	pthread_mutex_lock(&philo->eating);
	pthread_mutex_lock(&philo->args->print);
	// EATING
    output(get_timestamp(), philo, "is eating");
	pthread_mutex_unlock(&philo->args->print);
	philo->total_eat += 1;
	my_usleep(philo->args->eat_time);
	philo->last_eat = get_timestamp() - philo->args->time;
	pthread_mutex_unlock(&philo->args->forks[right]);
	pthread_mutex_unlock(&philo->args->forks[left]);
	pthread_mutex_unlock(&philo->eating);
}

void sleep(t_philo *philo)
{
    philo->status = SLEEPING;
	pthread_mutex_lock(&philo->args->print);
	// SLEEPING
    output(get_timestamp(), philo, "is sleeping");
	pthread_mutex_unlock(&philo->args->print);
	my_usleep(philo->args->sleep_time);
}

void think(t_philo *philo)
{
    philo->status = THINKING;
	pthread_mutex_lock(&philo->args->print);
	// THINKING
    output(get_timestamp(), philo, "is thinking");
	pthread_mutex_unlock(&philo->args->print);
}
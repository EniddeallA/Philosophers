/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhalid <akhalid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 06:40:55 by akhalid           #+#    #+#             */
/*   Updated: 2021/11/14 07:46:13 by akhalid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void get_forks(t_philo *philo)
{
    int pos;

    pos = philo->id;
    pthread_mutex_lock(&philo->args->fork[pos]);
    pthread_mutex_lock(&philo->args->fork[pos + 1 % philo->args->n_philo]);
    pthread_mutex_lock(&philo->args->print);
    printf("timestamp_in_ms %d has taken a fork", philo->id);
    pthread_mutex_lock(&philo->args->print);
}

void eat(t_philo *philo)
{
    philo->status = EATING;
    int pos;

    pos = philo->id;
    pthread_mutex_lock(&philo->eat);
    pthread_mutex_lock(&philo->args->print);
    printf("timestamp_in_ms %d is eating", philo->id);
    pthread_mutex_unlock(&philo->args->print);
    pthread_mutex_unlock(&philo->args->fork[pos]);
    pthread_mutex_unlock(&philo->args->fork[pos + 1 % philo->args->n_philo]);
    pthread_mutex_unlock(&philo->eat);
}

void sleep(t_philo *philo)
{
    philo->status = SLEEPING;
    pthread_mutex_lock(&philo->args->print);
    printf("timestamp_in_ms %d is sleeping", philo->id);
    pthread_mutex_lock(&philo->args->print);
}

void think(t_philo *philo)
{
    philo->status = THINKING;
    pthread_mutex_lock(&philo->args->print);
    printf("timestamp_in_ms %d is thinking", philo->id);
    pthread_mutex_lock(&philo->args->print);
}
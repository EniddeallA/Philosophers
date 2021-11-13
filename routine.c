/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhalid <akhalid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 08:05:33 by akhalid           #+#    #+#             */
/*   Updated: 2021/11/13 01:55:54 by akhalid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void get_forks(t_philo *philo)
{
    int i;
    
    i = philo->p_id;
    pthread_mutex_lock(&philo[i].fork);
    pthread_mutex_lock(&philo[(i + 1) % philo->args->n_philo].fork);
    pthread_mutex_lock(&philo[i].args->print);
    printf("Philosopher %d has taken a fork", i);
    pthread_mutex_unlock(&philo[i].args->print);
}

void eat(t_philo *philo)
{
    int i;
    
    i = philo->p_id;
    philo[i].status = EATING;
    pthread_mutex_lock(&philo[i].eating);
    pthread_mutex_lock(&philo[i].args->print);
    printf("Philosopher %d is eating", i);
    pthread_mutex_unlock(&philo[i].args->print);
    pthread_mutex_unlock(&philo[i].fork);
    pthread_mutex_unlock(&philo[(i + 1) % philo->args->n_philo].fork);
    pthread_mutex_unlock(&philo[i].eating);
}

void sleep(t_philo *philo)
{
    int i;

    i = philo->p_id;
    philo[i].status = SLEEPING;
    pthread_mutex_lock(&philo[i].args->print);
    printf("Philosopher %d is sleeping", i);
    pthread_mutex_unlock(&philo[i].args->print);
}

void think(t_philo *philo)
{
    int i;

    i = philo->p_id;
    philo[i].status = THINKING;
    pthread_mutex_lock(&philo[i].args->print);
    printf("Philosopher %d is thinking", i);
    pthread_mutex_unlock(&philo[i].args->print);
}

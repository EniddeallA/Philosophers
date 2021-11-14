/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhalid <akhalid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 15:30:27 by akhalid           #+#    #+#             */
/*   Updated: 2021/11/14 08:31:56 by akhalid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (1)
	{
		getting_forks(philo);
		eating(philo);
		sleeping(philo);
		thinking(philo);
	}
	return (0);
}

void	philosophers(t_philo *philo, t_args args)
{
	int	i;

	i = 0;
	while (i < args.n_philo)
	{
		pthread_create(&philo[i].philo, NULL, routine, (void *)&philo[i]);
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_philo	*philo;
	t_args	args;
	int		i;

	if (argc < 5 || argc > 6 || parse_args(argc, argv, &args))
		return (error_handler("Wrong usage."));
	philo = (t_philo *)malloc(sizeof(t_philo) * args.n_philo);
	args.fork = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t)
			* args.n_philo);
	i = 0;
	while (i < args.n_philo)
	{
		philo[i].id = i + 1;
		philo[i].args = &args;
		pthread_mutex_init(&args.fork[i], NULL);
		pthread_mutex_init(&philo[i].eat, NULL);
		i++;
	}
	pthread_mutex_init(&args.print, NULL);
	philosophers(philo, args);
	return (0);
}

/*
./a.out 
    -- number_of_philosophers -- time_to_die -- time_to_eat -- time_to_sleep 
    -- [number_of_times_each_philosopher_must_eat]
*/
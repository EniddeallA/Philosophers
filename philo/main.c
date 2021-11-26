/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhalid <akhalid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 15:30:27 by akhalid           #+#    #+#             */
/*   Updated: 2021/11/23 16:10:21 by akhalid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philosophers.h"

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

int	must_eat(t_philo *philo)
{
	int	i;
	int	done;

	if (philo->args->n_eat_time != -1)
	{
		done = 1;
		i = -1;
		while (++i < philo->args->n_philo)
			if (philo[i].total_eat < philo->args->n_eat_time)
				done = 0;
		if (done)
		{
			pthread_mutex_lock(&philo->args->print);
			printf("All philosophers have eaten at least");
			printf(" %d times each\n", philo->args->n_eat_time);
			pthread_mutex_unlock(&philo->args->print);
			return (1);
		}
	}
	return (0);
}

void	*supervisor(void *arg)
{
	t_philo	*philo;
	int		i;
	long	time;

	philo = (t_philo *)arg;
	while (1)
	{
		i = -1;
		while (++i < philo->args->n_philo)
		{
			if (!philo[i].status)
			{
				pthread_mutex_lock(&philo[i].eat);
				time = get_time_ms(philo->args->start_time);
				if ((time - philo[i].last_eat) >= philo->args->death_time)
					return (dead(time, philo[i].id, philo));
				pthread_mutex_unlock(&philo[i].eat);
			}
		}
		if (must_eat(philo))
			return (NULL);
		usleep(1e3);
	}
	return (0);
}

void	philosophers(t_philo *philo, t_args args)
{
	int			i;
	pthread_t	sudo;

	i = 0;
	philo->args->start_time = get_time_ms(0);
	while (i < args.n_philo)
	{
		pthread_create((&philo[i].philo), NULL, routine, (void *)&philo[i]);
		i += 2;
	}
	usleep(50);
	i = 1;
	while (i < args.n_philo)
	{
		pthread_create((&philo[i].philo), NULL, routine, (void *)&philo[i]);
		i += 2;
	}
	pthread_create(&sudo, NULL, supervisor, (void *)philo);
	pthread_join(sudo, NULL);
}

int	main(int argc, char **argv)
{
	t_philo	*philo;
	t_args	args;
	int		i;

	if (argc < 5 || argc > 6 || parse_args(argc, argv, &args))
		return (error_handler("Wrong usage."));
	args.fork = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t)
			* args.n_philo);
	philo = (t_philo *)malloc(sizeof(t_philo) * args.n_philo);
	i = 0;
	while (i < args.n_philo)
	{
		philo[i].id = i + 1;
		philo[i].args = &args;
		philo[i].status = 0;
		philo[i].last_eat = get_time_ms(philo->args->start_time);
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
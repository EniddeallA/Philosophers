/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhalid <akhalid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 08:05:09 by akhalid           #+#    #+#             */
/*   Updated: 2021/11/26 18:14:49 by akhalid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philosophers.h"

int	error_handler(char *str)
{
	printf("%s", str);
	return (-1);
}

int	ft_atoi(char *str)
{
	int	res;

	res = 0;
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (error_handler("Arguments contain bad character."));
		res = res * 10 + (*str - '0');
		str++;
	}
	return (res);
}

int	parse_args(int argc, char **argv, t_args *args)
{
	args->n_philo = ft_atoi(argv[1]);
	args->death_time = ft_atoi(argv[2]);
	args->eat_time = ft_atoi(argv[3]);
	args->sleep_time = ft_atoi(argv[4]);
	args->n_eat_time = -1;
	if (argc == 6)
		args->n_eat_time = ft_atoi(argv[5]);
	if (args->n_philo <= 0 || args->death_time < 60 || args->eat_time< 60
		|| args->sleep_time < 60 || args->n_eat_time <= 0)
		return (error_handler("Arguments can't be 0."));
	args->start_time = get_time_ms(0);
	return (0);
}

void	*dead(long time, int id, t_philo *philo)
{
	pthread_mutex_lock(&philo->args->print);
	printf("%ld %d died\n", time, id);
	return (0);
}

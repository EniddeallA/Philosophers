/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhalid <akhalid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 15:03:00 by  by akhalid       #+#    #+#             */
/*   Updated: 2021/11/16 00:56:03 by akhalid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <pthread.h>
# include <stdint.h>

# define EATING 1
# define THINKING 2
# define SLEEPING 3
# define DEAD 4

typedef struct s_args
{
	int				n_philo;
	int				death_time;
	int				eat_time;
	int				sleep_time;
	int				n_eat_time;
	long			start_time;
	pthread_mutex_t	print;
	pthread_mutex_t	*fork;
}				t_args;

typedef struct s_philo
{
	int				id;
	int				status;
	int				last_eat;
	pthread_t		philo;
	pthread_mutex_t	eat;
	t_args			*args;
}				t_philo;

int			parse_args(int argc, char **argv, t_args *args);
int			error_handler(char *str);
int			ft_atoi(char *str);
void		philosophers(t_philo *philo, t_args args);
void		*routine(void *arg);
void		getting_forks(t_philo *philo);
void		eating(t_philo *philo);
void		sleeping(t_philo *philo);
void		thinking(t_philo *philo);
long		get_time_ms(long time);
void		*supervisor(void *arg);

#endif
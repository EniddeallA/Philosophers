/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhalid <akhalid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*       Created: 2021/10/01 15:31:24 by akhalid           #+#    #+#             */
/*   Updated: 2021/10/23 15:40:12 by akhalid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include <pthread.h>
# include <stdlib.h>
# include <unistd.h>


# define EATING 1
# define THINKING 2
# define SLEEPING 3
# define DEAD 4

typedef struct s_args
{
    int n_philo;
    int die_time;
    int eat_time;
    int sleep_time;
    int n_eat_time;
    pthread_mutex_t *forks;
    pthread_mutex_t print;
}   t_args;

typedef struct s_philo
{
    pthread_t *philosopher;
    int id;
    t_args *args;
    int status;
    pthread_mutex_t eating;
}   t_philo;

int parse_args(int argc,char **argv, t_args *args);
int error_handler(char *str);


#endif
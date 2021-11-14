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
    int n_philo;
    uint64_t death_time;
    uint64_t eat_time;
    uint64_t sleep_time;
    int n_eat_time;
}   t_args;

typedef struct s_philo
{
    
}   t_philo;

int         parse_args(int argc,char **argv, t_args *args);
int         error_handler(char *str);
int         ft_atoi(char *str);

#endif
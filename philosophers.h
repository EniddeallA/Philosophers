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

// EATING 1
// THINKING 2
// SLEEPING 3
// DEAD 4

typedef struct s_args
{
    int n_philo;
    int die_time;
    int eat_time;
    int sleep_time;
    int n_eat_time;
    
}   t_args;

typedef struct s_philo
{
    t_args args;

}   t_philo;

void parse_args(int argc,char **argv, t_args *args);


#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhalid <akhalid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 15:31:24 by akhalid           #+#    #+#             */
/*   Updated: 2021/10/23 15:40:12 by akhalid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include <pthread.h>
# include <stdlib.h>
# include <unistd.h>

// SLEEPING 1
// EATING 2
// THINKING 3

typedef struct s_state
{
    int id;
    int state;
    
}   t_state;

typedef struct s_philo
{
    int n_philo;
    int die_time;
    int eat_time;
    int sleep_time;
    int n_eat_time;
    t_state state;
}   t_philo;

void parse_args(int argc,char **argv, t_philo **philo);


#endif
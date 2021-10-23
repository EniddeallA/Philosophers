/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhalid <akhalid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 15:30:27 by akhalid           #+#    #+#             */
/*   Updated: 2021/10/23 15:37:30 by akhalid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
/*
./a.out number_of_philosophers -- time_to_die -- time_to_eat -- time_to_sleep --
        [number_of_times_each_philosopher_must_eat]
*/

void parse_args(int argc,char **argv, t_philo **philo)
{
    (*philo)->n_philo = argv[0];
    (*philo)->die_time = argv[0];
    (*philo)->eat_time = argv[0];
    (*philo)->sleep_time = argv[0];
    if (argc == 5)
        (*philo)->n_eat_time = argv[0];
    else
        (*philo)->n_eat_time = -1;
}

int main(int argc, char **argv)
{
    t_philo *philo;

    if (argc < 4 || argc > 5)
    {
        printf("Wrong usage.");
        return (0);
    }
    philo = (t_philo*)malloc(sizeof(t_philo));
    parse_args(argc, argv, &philo);
    
    return (0);
}
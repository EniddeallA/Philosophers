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

void parse_args(int argc,char **argv, t_args *args)
{
    args->n_philo = argv[1];
    args->die_time = argv[2];
    args->eat_time = argv[3];
    args->sleep_time = argv[4];
    if (argc == 6)
        args->n_eat_time = argv[5];
    else
        args->n_eat_time = -1;
}

int main(int argc, char **argv)
{
    t_philo *philo;
    t_args args;

    if (argc < 5 || argc > 6)
    {
        printf("Wrong usage.");
        return (0);
    }
    parse_args(argc, argv, &args);
    philo = (t_philo*)malloc(sizeof(t_philo) * args.n_philo);
    
    return (0);
}
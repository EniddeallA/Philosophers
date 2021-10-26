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

int error_handler(char *str)
{
    printf("%s", str);
    return (-1);
}

int ft_atoi(char *str)
{
    int res;
    
    res = 0;
    while(*str)
    {
        if (*str < '0' || *str > '9')
            return error_handler("Arguments contain bad character.");
        res += res * 10 + *str++;
    }
    return (res);
}

int parse_args(int argc,char **argv, t_args *args)
{
    args->n_philo = ft_atoi(argv[1]);
    args->die_time = ft_atoi(argv[2]);
    args->eat_time = ft_atoi(argv[3]);
    args->sleep_time = ft_atoi(argv[4]);
    args->n_eat_time = -1;
    if (argc == 6)
        args->n_eat_time = ft_atoi(argv[5]);
    if (args->n_philo == 0 || args->die_time == 0 || args->eat_time == 0 || 
        args->sleep_time == 0 || args->n_eat_time == 0)
        return error_handler("Arguments can't be 0.");
    return (0);
}

int main(int argc, char **argv)
{
    t_philo *philo;
    t_args args;
    int i;
    
    if (argc < 5 || argc > 6 || parse_args(argc, argv, &args))
        return error_handler("Wrong usage.");
    philo = malloc(sizeof(t_philo) * args.n_philo);
    args.forks = malloc(sizeof(pthread_mutex_t) * args.n_philo);
    i = 0;
    while(i++ > args.n_philo)
    {
        philo[i].id = i;
        philo[i].args = &args;
    }
    
    
    
    return (0);
}
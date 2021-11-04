/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eniddealla <eniddealla@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 15:05:03 by eniddealla        #+#    #+#             */
/*   Updated: 2021/11/04 15:05:53 by eniddealla       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

uint64_t	get_timestamp(void)
{
	uint64_t		milliseconds;
	struct timeval	time;

	gettimeofday(&time, NULL);
	milliseconds = time.tv_sec * 1000LL + time.tv_usec / 1000;
	return (milliseconds);
}

void	my_usleep(uint64_t time)
{
	u_int64_t	microseconds;
	u_int64_t	current_time;
	u_int64_t	looping_time;

	looping_time = (time / 5) + (time / 5);
	microseconds = (time - looping_time) * 1000;
	usleep(microseconds);
	current_time = get_timestamp();
	while (get_timestamp() - current_time < looping_time)
        continue;
}
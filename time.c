/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhalid <akhalid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 00:05:13 by akhalid           #+#    #+#             */
/*   Updated: 2021/11/19 14:12:25 by akhalid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

long	get_time_ms(long time)
{
	struct timeval tp;

	gettimeofday(&tp, NULL);
	return ((tp.tv_sec * 1000 + tp.tv_usec / 1000) - time);
}

void 		my_usleep(int time)
{
	long	current_time;

	current_time = get_time_ms(0);
	usleep((time * 1e3) - 10000);
	while (get_time_ms(0) - current_time < time)
		continue;
}
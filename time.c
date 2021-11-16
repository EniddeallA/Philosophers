/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhalid <akhalid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 00:05:13 by akhalid           #+#    #+#             */
/*   Updated: 2021/11/16 01:48:28 by akhalid          ###   ########.fr       */
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
	int		s_sleep_time;
	int		b_sleep_time;

	s_sleep_time = time * 30 / 100;
	b_sleep_time = (time * 70/100) * 1000;
	usleep(b_sleep_time);
	current_time = get_time_ms(0);
	while (get_time_ms(0) - current_time < s_sleep_time)
		continue;
}
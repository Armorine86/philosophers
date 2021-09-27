/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 08:29:48 by mmondell          #+#    #+#             */
/*   Updated: 2021/09/24 15:34:32 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	sleep_timer(long milliseconds)
{
	struct timeval	time;
	struct timeval	time_a;

	gettimeofday(&time, NULL);
	gettimeofday(&time_a, NULL);
	while (time_diff(time, time_a) < (unsigned long)milliseconds)
	{
		gettimeofday(&time_a, NULL);
		usleep(200);
	}
}

unsigned long	time_diff(struct timeval first, struct timeval second)
{
	unsigned long	start;
	unsigned long	finish;

	start = (first.tv_sec * 1000) + (first.tv_usec / 1000);
	finish = (second.tv_sec * 1000) + (second.tv_usec / 1000);
	return (ft_abs(start - finish));
}

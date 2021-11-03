/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 08:29:48 by mmondell          #+#    #+#             */
/*   Updated: 2021/11/03 14:45:55 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	sleep_timer(t_philo *p, long param)
{
	long	time;

	time = time_now();
	while ((time_now() - time) < param)
	{
		if (!philo_is_dead(p))
			usleep(50);
		else
			return ;
		continue ;
	}
}

long	time_now(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

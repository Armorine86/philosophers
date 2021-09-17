/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 08:29:48 by mmondell          #+#    #+#             */
/*   Updated: 2021/09/17 08:15:04 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

long	time_diff(t_philo *p)
{
	long	diff;

	diff = p->last_meal + p->starve;
	return (ft_abs(diff));
}

long	clock_now(t_philo *p)
{
	long	time;

	time = 0;
	time = p->m->clock - get_time();
	return (ft_abs(time));
}

long	get_time(void)
{
	struct timeval	time;
	long			s1;
	long			s2;

	gettimeofday(&time, NULL);
	s1 = time.tv_sec * 1000;
	s2 = time.tv_usec / 1000;
	return (s1 + s2);
}

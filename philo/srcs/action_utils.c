/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 15:51:38 by mmondell          #+#    #+#             */
/*   Updated: 2021/09/20 21:07:00 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

bool	fork_available(t_philo *p)
{
	if (p->id == p->m->last_philo)
	{
		if (p->fork == 0 || p->m->philo[0].fork == 0)
			return (true);
		return (false);
	}
	else
	{
		if (p->fork == 0 || p->m->philo[p->id].fork == 0)
			return (true);
		return (false);
	}
}

void	take_forks(t_philo *p)
{
	p->fork = 1;
	printf("%ld Philo %d took his fork\n", clock_now(p), p->id);
	if (p->id == p->m->last_philo)
	{
		printf("%ld Philo %d took philo %d's fork\n", clock_now(p), p->id, p->m->philo[0].id);	
		p->m->philo[0].fork = 1;
	}
	else
	{
		p->m->philo[p->id].fork = 1;
		printf("%ld Philo %d took philo %d's fork\n", clock_now(p), p->id, p->m->philo[p->id].id);
	}
}

bool	check_if_starving(t_philo *p)
{
	long	is_dead;

	is_dead = get_time();
	is_dead = is_dead - p->last_meal;
	if (is_dead > p->m->settings->time_die)
		return (true);
	return (false);
}

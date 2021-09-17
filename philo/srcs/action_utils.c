/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 15:51:38 by mmondell          #+#    #+#             */
/*   Updated: 2021/09/16 16:16:42 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

bool	fork_available(t_philo *p)
{
	if (p->id == p->m->last_philo)
	{
		if (p->fork == 0 && p->m->philo[0].fork == 0)
			return (true);
	}
	if (p->fork == 0 && p->m->philo[p->id].fork == 0)
		return (true);
	return (false);
}

void	unlock_mutex(t_philo *p)
{
	pthread_mutex_unlock(p->fork_lock);
	printf("%ld Philo %d fork is unlocked\n", clock_now(p), p->id);
	if (p->id == p->m->last_philo)
	{
		pthread_mutex_unlock(p->m->philo[0].fork_lock);
		printf("%ld Philo %d fork is unlocked\n", clock_now(p), p->m->philo[0].id);
	}
	else
	{
		pthread_mutex_unlock(p->m->philo[p->id].fork_lock);
		printf("%ld Philo %d fork is unlocked\n", clock_now(p), p->m->philo[p->id].id);
	}
}

void	lock_mutex(t_philo *p)
{
	pthread_mutex_lock(p->fork_lock);
	printf("%ld Philo %d fork is locked\n", clock_now(p), p->id);
	if (p->id == p->m->last_philo)
	{
		pthread_mutex_lock(p->m->philo[0].fork_lock);
		printf("%ld Philo %d fork is locked\n", clock_now(p), p->m->philo[0].id);
	}
	else
	{
		pthread_mutex_lock(p->m->philo[p->id].fork_lock);
		printf("%ld Philo %d fork is locked\n", clock_now(p), p->m->philo[p->id].id);
	}
}
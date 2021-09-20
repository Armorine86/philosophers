/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 15:51:38 by mmondell          #+#    #+#             */
/*   Updated: 2021/09/20 15:30:53 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

bool	fork_available(t_philo *p)
{
	lock_mutex(p);
	if (p->id == p->m->last_philo)
	{
		if (p->fork == 0 && p->m->philo[0].fork == 0)
		{
			p->fork = 1;
			printf("%ld Philo %d took his fork\n", clock_now(p), p->id);
			p->m->philo[0].fork = 1;
			printf("%ld Philo %d took philo %d's fork\n\n",clock_now(p), p->id, p->m->philo[0].id);
			unlock_mutex(p);
			return (true);
		}
	}
	if (p->fork == 0 && p->m->philo[p->id].fork == 0)
	{
		p->fork = 1;
		printf("%ld Philo %d took his fork\n", clock_now(p), p->id);
		p->m->philo[p->id].fork = 1;
		printf("%ld Philo %d took philo %d's fork\n\n",clock_now(p), p->id, p->m->philo[p->id].id);
		unlock_mutex(p);
		return (true);
	}
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
	p->fork = 1;
	pthread_mutex_unlock(p->fork_lock);
	printf("%ld Philo %d fork is locked\n", clock_now(p), p->id);
	if (p->id == p->m->last_philo)
	{
		pthread_mutex_lock(p->m->philo[0].fork_lock);
		p->m->philo[0].fork = 1;
		printf("%ld Philo %d fork is locked\n", clock_now(p), p->m->philo[0].id);
		pthread_mutex_unlock(p->m->philo[0].fork_lock);
	}
	else
	{
		pthread_mutex_lock(p->m->philo[p->id].fork_lock);
		printf("%ld Philo %d fork is locked\n", clock_now(p), p->m->philo[p->id].id);
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

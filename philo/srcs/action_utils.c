/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 15:51:38 by mmondell          #+#    #+#             */
/*   Updated: 2021/09/27 15:23:24 by mmondell         ###   ########.fr       */
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
	else
	{
		if (p->fork == 0 && p->m->philo[p->id].fork == 0)
			return (true);
	}
	return (false);
}

void	fork_unlock(t_philo *p)
{
	pthread_mutex_unlock(p->fork_lock);
	if (p->id == p->m->last_philo)
		pthread_mutex_unlock(p->m->philo[0].fork_lock);
	else
		pthread_mutex_unlock(p->m->philo[p->id].fork_lock);
}

void	take_forks(t_philo *p)
{
	pthread_mutex_lock(p->fork_lock);
	p->fork = 1;
	print_state(p, "has taken a fork");
	if (p->m->settings->total_philo < 2)
		return ;
	if (p->id == p->m->last_philo)
	{
		pthread_mutex_lock(p->m->philo[0].fork_lock);
		p->m->philo[0].fork = 1;
		print_state(p, "has taken a fork");
		p->state = s_eat;
		end_of_queue(p);
	}
	else
	{
		pthread_mutex_lock(p->m->philo[p->id].fork_lock);
		p->m->philo[p->id].fork = 1;
		print_state(p, "has taken a fork");
		p->state = s_eat;
		end_of_queue(p);
	}
}

void	drop_forks(t_philo *p)
{
	pthread_mutex_lock(p->fork_lock);
	p->meal++;
	p->fork = 0;
	pthread_mutex_unlock(p->fork_lock);
	if (p->id == p->m->last_philo)
	{
		p->m->philo[0].fork = 0;
		pthread_mutex_unlock(p->m->philo[0].fork_lock);
	}
	else
	{
		p->m->philo[p->id].fork = 0;
		pthread_mutex_unlock(p->m->philo[p->id].fork_lock);
	}
}

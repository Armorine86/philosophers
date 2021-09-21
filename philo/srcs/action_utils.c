/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 15:51:38 by mmondell          #+#    #+#             */
/*   Updated: 2021/09/21 15:28:42 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	take_forks(t_philo *p)
{
	pthread_mutex_lock(p->fork_lock);
	p->fork = 1;
	print_state(p, "has taken a fork");
	if (p->id == p->m->last_philo)
	{
		pthread_mutex_lock(p->m->philo[0].fork_lock);	
		p->m->philo[0].fork = 1;
		print_state(p, "has taken a fork");
	}
	else
	{
		pthread_mutex_lock(p->m->philo[p->id].fork_lock);	
		p->m->philo[p->id].fork = 1;
		print_state(p, "has taken a fork");
	}
}

void	drop_forks(t_philo *p)
{
	p->fork = 0;
	pthread_mutex_unlock(p->fork_lock);
	print_state(p, "DROPPED a fork");
	if (p->id == p->m->last_philo)
	{
		print_state(p, "DROPPED a fork");
		p->m->philo[0].fork = 0;
		pthread_mutex_unlock(p->m->philo[0].fork_lock);	

	}
	else
	{
		p->m->philo[p->id].fork = 0;
		pthread_mutex_unlock(p->m->philo[p->id].fork_lock);
		print_state(p, "DROPPED a fork");
	}
}

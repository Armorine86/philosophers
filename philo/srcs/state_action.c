/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state_action.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 13:29:21 by mmondell          #+#    #+#             */
/*   Updated: 2021/09/20 21:06:40 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	time_to_eat(t_philo *p)
{
	pthread_mutex_lock(p->fork_lock);
	printf("%ld Philo %d is EATING!\n", clock_now(p), p->id);
	p->last_meal = get_time();
	printf("%ld Philo %d DROPPED his fork\n", clock_now(p), p->id);
	p->fork = 0;
	if (p->id == p->m->last_philo)
	{
		printf("%ld Philo %d DROPPED philo %d's fork\n", clock_now(p), p->id, p->m->philo[0].id);	
		p->m->philo[0].fork = 0;
	}
	else
	{
		p->m->philo[p->id].fork = 0;
		printf("%ld Philo %d DROPPED philo %d's fork\n", clock_now(p), p->id, p->m->philo[p->id].id);	
	}
	p->state = s_sleep;
	end_of_queue(p);
	pthread_mutex_unlock(p->fork_lock);
}

void	time_to_sleep(t_philo *p)
{
	usleep(200 * 1000);
	p->state = s_think;
}

void	prepare_to_eat(t_philo *p)
{
	int	i;

	i = p->m->settings->total_philo - 1;
	while (true)
	{
		pthread_mutex_lock(&p->m->queue_lock);
		if (p->id == p->m->queue[i] || p->id == p->m->queue[i - 1])
		{
			if (fork_available(p))
			{
				take_forks(p);
				p->state = s_eat;
				pthread_mutex_unlock(&p->m->queue_lock);	
				break;
			}
		}
		pthread_mutex_unlock(&p->m->queue_lock);
	}
}

// TODO	Fix the timeget functions. Results are probably not accurate and philo dies for no reason
// TODO	Make sure only one thread prints at the same time.
// TODO Confirm threads priority for the routine. Philo5 should always go last.

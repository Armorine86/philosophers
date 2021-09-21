/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state_action.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 13:29:21 by mmondell          #+#    #+#             */
/*   Updated: 2021/09/20 22:33:35 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	time_to_eat(t_philo *p)
{
	pthread_mutex_lock(p->fork_lock);
	//pthread_mutex_lock(p->m->philo[p->id].fork_lock);
	printf("%ld Philo %d is EATING!\n", clock_now(p), p->id);
	p->last_meal = get_time();
	drop_forks(p);
	p->state = s_sleep;
	end_of_queue(p);
	printf("%ld Philo %d is now at back of queue\n", clock_now(p), p->id);
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
			take_forks(p);
			p->state = s_eat;
			pthread_mutex_unlock(&p->m->queue_lock);	
			break;
		}
		pthread_mutex_unlock(&p->m->queue_lock);
	}
}

// TODO	Fix the timeget functions. Results are probably not accurate and philo dies for no reason
// TODO make sure the logic is not sequential.
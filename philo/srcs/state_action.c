/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state_action.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 13:29:21 by mmondell          #+#    #+#             */
/*   Updated: 2021/09/15 13:58:50 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	time_to_eat(t_philo *p)
{
	p->starve = get_time();
	if (time_diff(p) > p->m->settings->time_die)
	{
		p->starve = s_die;
		return ;
	}
	printf("%ld philo %d is eating\n", p->m->clock, p->id);
	p->satiated = 1;
	p->fork = 0;
	if (p->fork == 0)
		pthread_mutex_unlock(p->fork_lock);
	if (p->m->settings->total_meals != 0)
		p->meals = 1;
	p->last_meal = get_time();
	p->state = s_sleep;
}

void	time_to_sleep(t_philo *p)
{
	printf("%ld philo %d is sleeping\n", p->m->clock, p->id);
	sleep(2 / 100);
	
	p->state = s_think;
}

void	prepare_to_eat(t_philo *p)
{
	p->satiated = 0;
	if (p->priority == 1)
		sleep(10 / 100);
	if (p->fork == 0 && p->m->philo[p->id].fork == 0)
	{
			
		p->fork = 1;
		printf("%ld philo %d[%d] priority: %d has taken his fork\n", clock_now(p), p->id, p->id - 1, p->priority);
		pthread_mutex_lock(p->fork_lock);
		printf("philo %d fork is locked\n\n", p->id);
		if (p->id == p->m->settings->total_philo)
			p->m->philo[0].fork = 1;
		else
		{
			p->m->philo[p->id].fork = 1;
			printf("%ld philo %d has taken philo %d's fork  STATE IS: %u\n", clock_now(p), p->id,p->m->philo[p->id].id, p->state);
			pthread_mutex_lock(p->m->philo[p->id].fork_lock);
			p->state = s_eat;
			printf("philo %d fork is locked\n\n", p->m->philo[p->id].id);
		}
	}
	else
		return ;
	
	
	
	
	
	
	
	
	
	
	
	
	
	// if (p->fork == 1)
	// {
	// 	printf("philo %d fork is locked\n\n", p->id);
	// 	pthread_mutex_lock(p->fork_lock);
	// }
	// if (p->id == p->m->settings->total_philo)
	// {
	// 	printf("****philo %d fork state is: %d****\n\n", p->id, p->fork);
	// 	if (p->m->philo[0].fork == 0)
	// 	{
	// 		printf("%ld philo %d has taken a fork  STATE IS: %d\n", p->m->clock, p->id, p->state);
	// 		p->m->philo[0].fork = 1;
	// 		p->state = s_eat;
	// 		return ;
	// 	}
	// }
	// else if (p->m->philo[p->id].fork == 0)
	// {
	// 	p->m->philo[p->id].fork = 1;
	// 	p->state = s_eat;
	// 	printf("%ld philo %d has taken philo %d's fork  STATE IS: %u\n", clock_now(p), p->id,p->m->philo[p->id].id, p->state);
	// 	return ;
	// }
}

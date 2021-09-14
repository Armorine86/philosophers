/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state_action.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 13:29:21 by mmondell          #+#    #+#             */
/*   Updated: 2021/09/14 15:26:17 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	time_to_eat(t_philo *p)
{
	p->starve = get_time();
	if (p->starve + p->last_meal > p->m->settings->time_die)
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
		p->meals++;
	p->last_meal = get_time();
	p->state = s_sleep;
}

void	time_to_sleep(t_philo *p)
{
	printf("%ld philo %d is sleeping\n", p->m->clock, p->id);
	sleep(2 / 1000);
	p->state = s_think;
}

void	prepare_to_eat(t_philo *p)
{
	p->satiated = 0;
	if (p->priority == 1)
	{
		p->fork = 1;
		printf("%ld philo %d has taken a fork\n", p->m->clock, p->id);
		if (p->fork == 1)
			pthread_mutex_lock(p->fork_lock);
		if (p->id == p->m->settings->total_philo)
		{
			if (p->m->philo[0].fork == 0)
			{
				printf("%ld philo %d has taken a fork\n", p->m->clock, p->id);
				p->m->philo[0].fork = 1;
				p->state = s_eat;
			}
		}
		else if (p->m->philo[p->id + 1].fork == 0)
		{
			printf("%ld philo %d has taken a fork\n", p->m->clock, p->id);
			p->m->philo[p->id + 1].fork = 1;
			p->state = s_eat;
		}
	}
}

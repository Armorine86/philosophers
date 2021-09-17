/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state_action.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 13:29:21 by mmondell          #+#    #+#             */
/*   Updated: 2021/09/17 08:19:27 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	time_to_eat(t_philo *p)
{
	p->fork = 0;
	printf("%ld Philo %d is eating\n", clock_now(p), p->id);
	printf("%ld Philo %d drops his fork\n", clock_now(p), p->id);
	if (p->id == p->m->last_philo)
	{
		p->m->philo[0].fork = 0;
		printf("%ld Philo %d drops philo %d's fork\n\n",clock_now(p), p->id, p->m->philo[0].id);
	}
	else
	{
		p->m->philo[p->id].fork = 0;
		printf("%ld Philo %d drops philo %d's fork\n\n",clock_now(p), p->id, p->m->philo[p->id].id);
	}
	unlock_mutex(p);
	sleep(2);
	p->satiated = 1;
	p->state = s_sleep;
}

void	time_to_sleep(t_philo *p)
{
	sleep(2 / 100);
	p->state = s_think;
}

void	prepare_to_eat(t_philo *p)
{
	get_in_queue(p);
	lock_mutex(p);
	if (fork_available(p))
	{
		p->fork = 1;
		printf("%ld Philo %d took his fork\n", clock_now(p), p->id);
		if (p->id == p->m->last_philo)
		{
			p->m->philo[0].fork = 1;
			printf("%ld Philo %d took philo %d's fork\n\n",clock_now(p), p->id, p->m->philo[0].id);
		}
		else
			p->m->philo[p->id].fork = 1;
		printf("%ld Philo %d took philo %d's fork\n\n",clock_now(p), p->id, p->m->philo[p->id].id);
		p->state = s_eat;
		sleep(2);
	}
	else
		return ;
}

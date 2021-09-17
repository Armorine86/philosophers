/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state_action.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 13:29:21 by mmondell          #+#    #+#             */
/*   Updated: 2021/09/17 15:22:31 by mmondell         ###   ########.fr       */
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
	p->last_meal = get_time();
	p->state = s_sleep;
	if (check_if_starving(p))
	{
		p->state = s_die;
		return ;
	}
}

void	time_to_sleep(t_philo *p)
{
	usleep(200 * 1000);
	unlock_mutex(p);
	p->state = s_think;
}

void	prepare_to_eat(t_philo *p)
{
	while (!fork_available(p))
	{
		return ;
	}
	lock_mutex(p);
	p->state = s_eat;
	return ;
}

// TODO	Fix the timeget functions. Results are probably not accurate and philo dies for no reason
// TODO	Make sure only one thread prints at the same time.
// TODO Confirm threads priority for the routine. Philo5 should always go last.

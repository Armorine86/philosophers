/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state_action.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 13:29:21 by mmondell          #+#    #+#             */
/*   Updated: 2021/09/14 13:58:24 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	time_to_eat(t_philo *p)
{
	p->last_meal = ft_abs(p->last_meal += get_time());
	p->satiated = 1;
	p->fork = 0;
	p->start_eat = get_time();
	if (p->fork == 0)
		pthread_mutex_unlock(p->fork_lock);
	if (p->m->settings->total_meals != 0)
		p->meals++;
	p->state = s_sleep;
}

void	time_to_sleep(t_philo *p)
{
	
}

void	prepare_to_eat(t_philo *p)
{
	p->satiated = 0;
	if (p->priority == 1)
	{
		p->fork = 1;
		ft_putstr_fd("%d philo %d has taken a fork", 1);
		if (p->fork == 1)
			pthread_mutex_lock(p->fork_lock);
		if (p->id = p->m->settings->total_philo)
		{
			if (p->m->philo[0].fork == 0)
			{
				ft_putstr_fd("%d philo %d has taken a fork", 1);
				p->m->philo[0].fork == 1;
				p->state = s_eat;
			}
		}
		else if (p->m->philo[p->id + 1].fork == 0)
		{
			ft_putstr_fd("%d philo %d has taken a fork", 1);
			p->m->philo[p->id + 1].fork == 1;
			p->state = s_eat;
		}
	}
}

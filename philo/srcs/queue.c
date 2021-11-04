/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 08:22:20 by mmondell          #+#    #+#             */
/*   Updated: 2021/11/04 09:41:46 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

bool	fork_available(t_philo *p)
{
	if (philo_is_dead(p))
		return (false);
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

void	place_in_queue(t_main *m)
{
	int	i;
	int	j;

	j = 1;
	i = 0;
	while (i < m->settings->total_philo)
	{
		j = 1;
		if (m->philo[i].id == m->last_philo)
			m->queue[0] = m->philo[i].id;
		else if (m->philo[i].priority == 0)
		{
			while (m->queue[j] != 0)
				j++;
			m->queue[j] = m->philo[i].id;
		}
		else
		{
			j += m->total_priority;
			while (m->queue[j] != 0)
				j++;
			m->queue[j] = m->philo[i].id;
		}
		i++;
	}
}

void	end_of_queue(t_philo *p)
{
	int	i;
	int	tmp;

	i = p->m->settings->total_philo - 1;
	tmp = p->m->queue[i];
	while (i >= 0)
	{
		p->m->queue[i] = p->m->queue[i - 1];
		--i;
	}
	p->m->queue[0] = tmp;
}

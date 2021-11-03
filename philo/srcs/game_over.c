/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_over.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 14:37:48 by mmondell          #+#    #+#             */
/*   Updated: 2021/11/03 10:51:30 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

bool	philo_are_full(t_main *m, int total_philo)
{
	int	i;

	i = 0;
	while (m->philo[i].meal >= m->settings->total_meals)
		i++;
	if (i == total_philo)
		return (true);
	return (false);
}

void	check_meal_quota(t_main *m, int total_philo)
{
	if (m->settings->meal_quota == 0)
		return ;
	while (!m->game_over)
	{
		usleep(100);
		if (philo_are_full(m, total_philo))
		{
			m->game_over = 1;
			printf(QUOTA_MSG);
		}
	}
}

bool	philo_is_starving(t_philo *p)
{
	pthread_mutex_lock(&p->m->print_lock);
	if ((time_now() - p->last_meal) > p->m->settings->time_die)
	{
		pthread_mutex_unlock(&p->m->print_lock);
		return (true);
	}
	pthread_mutex_unlock(&p->m->print_lock);
	return (false);
}

void	*death_watch(void *arg)
{
	t_philo	*p;

	p = (t_philo *)arg;
	while (!p->m->game_over)
	{
		pthread_mutex_lock(&p->m->death_lock);
		if (philo_is_starving(p))
		{
			print_state(p, DEAD);
			p->m->game_over = 1;
			pthread_mutex_unlock(&p->m->death_lock);
			break ;
		}
		pthread_mutex_unlock(&p->m->death_lock);
	}
	return (NULL);
}

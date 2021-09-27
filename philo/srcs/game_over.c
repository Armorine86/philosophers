/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_over.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 14:37:48 by mmondell          #+#    #+#             */
/*   Updated: 2021/09/27 15:06:27 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

bool	philo_is_starving(t_philo *p)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	if (time_diff(time, p->last_meal) > (UL)p->m->settings->time_die)
	{
		print_state(p, "\e[31m\e[40mdied\e[0m 💀");
		p->m->game_over = 1;
		pthread_mutex_unlock(&p->m->death_lock);
		return (true);
	}
	pthread_mutex_unlock(&p->m->death_lock);
	return (false);
}

bool	philo_is_full(t_main *m, int i)
{
	if (m->philo[i].meal == m->settings->total_meals)
		return (true);
	return (false);
}

void	check_meal_quota(t_main *m, int total_philo)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	if (m->settings->meal_quota == 0)
		return ;
	while (!m->game_over)
	{
		i = 0;
		count = 0;
		while (i < total_philo)
		{
			if (philo_is_full(m, i))
				count++;
			i++;
		}
		if (count == total_philo)
		{
			m->game_over = 1;
			printf("\e[95m\e[4mAll Philos Reached The Meal Quota!\n");
		}
	}
}

void	*death_watch(void *arg)
{
	t_philo	*p;

	p = (t_philo *)arg;
	while (!p->m->game_over)
	{
		pthread_mutex_lock(&p->m->death_lock);
		if (philo_is_starving(p))
			break ;
	}
	return (NULL);
}

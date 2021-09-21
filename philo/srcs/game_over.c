/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_over.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 14:37:48 by mmondell          #+#    #+#             */
/*   Updated: 2021/09/21 15:30:39 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

bool	philo_is_starving(t_main *m, struct timeval time, int i)
{
	if (time_diff(time, m->philo[i].last_meal) > (unsigned long)m->settings->time_die)
	{
		print_state(&m->philo[i], "died");
		m->philo[i].state = s_dead;
		m->game_over = 1;
		return (true);
	}
	return (false);
}

bool	philos_are_full(t_main *m)
{
	int i;

	i = 0;
	if (m->settings->meal_quota == 0)
		return (false);
	while (i < m->settings->total_philo)
	{
		if (m->philo[i].meal < m->settings->total_meals)
			return (false);
		i++;
	}
	return (true);
}

bool	check_meal_quota(t_main *m, int i)
{
	if (m->settings->meal_quota == 0)
		return (false);
	if (m->philo[i].meal < m->settings->total_meals)
		return (false);
	return (true);
	// if (philos_are_full(m))
	// {
	// 	m->game_over = 1;
	// 	return (true);
	// }
	// return (false);
}

// TODO Need to fix the death timer. Philos dies too quickly
void	death_watch(t_main *m)
{
	struct timeval time;
	int i;

	i = 0;
	usleep(50 * 1000);
	while (!m->game_over)
	{
		i = 0;
		while (i < m->settings->total_philo)
		{
			usleep(50 * 1000);
			gettimeofday(&time, NULL);
			if (philo_is_starving(m, time, i))
				break;
			if (check_meal_quota(m, i))
				print_state(m->philo, "All philos reached the meal quota!");
			i++;
		}
	}
}

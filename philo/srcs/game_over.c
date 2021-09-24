/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_over.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 14:37:48 by mmondell          #+#    #+#             */
/*   Updated: 2021/09/24 15:17:07 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

bool	philo_is_starving(t_main *m, struct timeval time, int i)
{
	if (time_diff(time, m->philo[i].last_meal)
		> (unsigned long)m->settings->time_die)
	{
		print_state(&m->philo[i], "died");
		m->game_over = 1;
		return (true);
	}
	return (false);
}

bool	check_meal_quota(t_main *m, int i)
{
	int	total_meal;
	int	count;
	int	j;

	j = 0;
	count = 0;
	total_meal = m->settings->total_meals * m->settings->total_philo;
	if (m->settings->meal_quota == 0)
		return (false);
	while (i < m->settings->total_philo)
	{
		count += m->philo[i].meal;
		i++;
	}
	if (count >= total_meal)
	{
		m->game_over = 1;
		return (true);
	}
	return (false);
}

void	death_watch(t_main *m)
{
	struct timeval	time;
	int				i;

	while (!m->game_over)
	{
		i = 0;
		while (i < m->settings->total_philo)
		{
			usleep(50 * 1000);
			gettimeofday(&time, NULL);
			if (philo_is_starving(m, time, i))
				break ;
			i++;
			if (check_meal_quota(m, i))
			{
				printf("All philos reached the meal quota!\n");
				break ;
			}
		}
	}
}

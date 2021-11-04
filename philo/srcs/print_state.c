/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_state.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 14:52:00 by mmondell          #+#    #+#             */
/*   Updated: 2021/11/04 14:23:11 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	meal_quota_reached(t_main *m)
{
	if (m->settings->meal_quota == 0)
		return ;
	while (!m->game_over)
	{
		pthread_mutex_lock(&m->meal_lock);
		if (m->satiated == m->settings->total_philo)
		{
			m->game_over = 1;
			printf(QUOTA_MSG);
			pthread_mutex_unlock(&m->meal_lock);
			break ;
		}
		pthread_mutex_unlock(&m->meal_lock);
	}
}

bool	philo_is_full(t_philo *p)
{
	if (p->m->game_over)
		return (true);
	if (p->m->settings->meal_quota == 0)
		return (false);
	if (p->meal == p->m->settings->total_meals)
		return (true);
	return (false);
}

bool	philo_is_dead(t_philo *p)
{
	unsigned long	current_time;

	pthread_mutex_lock(&p->m->death_lock);
	current_time = time_now() - p->m->clock;
	if (p->m->game_over)
	{
		pthread_mutex_unlock(&p->m->death_lock);
		return (false);
	}
	if ((time_now() - p->last_meal) > p->m->settings->time_die)
	{
		p->m->game_over = 1;
		printf(PRINT_MSG, current_time, p->id, DEAD);
		pthread_mutex_unlock(&p->m->death_lock);
		return (true);
	}
	pthread_mutex_unlock(&p->m->death_lock);
	return (false);
}

int	print_state(t_philo *p, char *str)
{
	unsigned long	current_time;

	pthread_mutex_lock(&p->m->print_lock);
	current_time = time_now() - p->m->clock;
	if (p->state == s_eat)
		p->last_meal = time_now();
	if (!philo_is_full(p) && !philo_is_dead(p))
		printf(PRINT_MSG, current_time, p->id, str);
	else
	{
		pthread_mutex_unlock(&p->m->print_lock);
		return (1);
	}
	pthread_mutex_unlock(&p->m->print_lock);
	return (0);
}

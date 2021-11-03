/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_state.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 14:52:00 by mmondell          #+#    #+#             */
/*   Updated: 2021/11/03 16:29:52 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

bool	meal_quota_reached(t_philo *p)
{
	if (p->m->settings->meal_quota == 0)
		return (false);
	pthread_mutex_lock(&p->m->meal_lock);
	if (p->m->satiated == p->m->settings->total_philo)
	{
		p->m->game_over = 1;
		p->state = s_full;
		printf(QUOTA_MSG);
		pthread_mutex_unlock(&p->m->meal_lock);
		return (true);
	}
	pthread_mutex_unlock(&p->m->meal_lock);
	return (false);
}

bool	philo_is_dead(t_philo *p)
{
	unsigned long	current_time;

	current_time = time_now() - p->m->clock;
	if (p->m->game_over)
		return (false);
	if ((time_now() - p->last_meal) > p->m->settings->time_die)
	{
		p->m->game_over = 1;
		p->state = s_dead;
		printf(PRINT_MSG, current_time, p->id, DEAD);
		return (true);
	}
	return (false);
}

int	print_state(t_philo *p, char *str)
{
	unsigned long	current_time;

	pthread_mutex_lock(&p->m->print_lock);
	current_time = time_now() - p->m->clock;
	if (p->m->game_over)
	{
		pthread_mutex_unlock(&p->m->print_lock);
		return (1);
	}
	if (p->state == s_eat)
		p->last_meal = time_now();
	if (philo_is_dead(p))
	{
		pthread_mutex_unlock(&p->m->print_lock);
		return (1);
	}
	printf(PRINT_MSG, current_time, p->id, str);
	pthread_mutex_unlock(&p->m->print_lock);
	return (0);
}

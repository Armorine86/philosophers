/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_state.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 14:52:00 by mmondell          #+#    #+#             */
/*   Updated: 2021/11/03 13:46:20 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

bool	philo_is_dead(t_philo *p)
{
	if ((time_now() - p->last_meal) > p->m->settings->time_die)
		return (true);
	return (false);
}

int	print_state(t_philo *p, char *str)
{
	unsigned long	current_time;

	pthread_mutex_lock(&p->m->print_lock);
	if (p->m->game_over)
	{
		pthread_mutex_unlock(&p->m->print_lock);
		return (1);
	}
	current_time = time_now() - p->m->clock;
	if (p->state == s_eat)
		p->last_meal = time_now();
	if (philo_is_dead(p))
	{
		p->m->game_over = 1;
		printf(PRINT_MSG, current_time, p->id, DEAD);
		pthread_mutex_unlock(&p->m->print_lock);
		return (1);
	}
	printf(PRINT_MSG, current_time, p->id, str);
	pthread_mutex_unlock(&p->m->print_lock);
	return (0);
}

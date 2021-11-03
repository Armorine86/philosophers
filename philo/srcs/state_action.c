/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state_action.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 13:29:21 by mmondell          #+#    #+#             */
/*   Updated: 2021/11/03 16:31:15 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	time_to_eat(t_philo *p)
{
	if (print_state(p, "is eating"))
		return ;
	sleep_timer(p, p->m->settings->time_eat);
	pthread_mutex_lock(&p->m->meal_lock);
	p->meal++;
	if (p->meal >= p->m->settings->total_meals)
		p->m->satiated++;
	pthread_mutex_unlock(&p->m->meal_lock);
	drop_forks(p);
	p->state = s_sleep;
}

void	time_to_sleep(t_philo *p)
{
	if (print_state(p, "is sleeping"))
		return ;
	sleep_timer(p, p->m->settings->time_sleep);
	if (print_state(p, "is thinking"))
		return ;
	p->state = s_think;
}

void	prepare_to_eat(t_philo *p)
{
	int	i;

	i = p->m->settings->total_philo - 1;
	while (!p->m->game_over)
	{
		pthread_mutex_lock(&p->m->queue_lock);
		if (fork_available(p))
		{
			take_forks(p);
			fork_unlock(p);
			pthread_mutex_unlock(&p->m->queue_lock);
			break ;
		}
		pthread_mutex_unlock(&p->m->queue_lock);
	}
}

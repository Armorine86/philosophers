/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state_action.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 13:29:21 by mmondell          #+#    #+#             */
/*   Updated: 2021/09/27 15:20:36 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	time_to_eat(t_philo *p)
{
	print_state(p, "is eating");
	drop_forks(p);
	p->state = s_sleep;
	sleep_timer(p->m->settings->time_eat);
}

void	time_to_sleep(t_philo *p)
{
	print_state(p, "is sleeping");
	sleep_timer(p->m->settings->time_sleep);
	p->state = s_think;
	print_state(p, "is thinking");
}

void	prepare_to_eat(t_philo *p)
{
	int	i;

	i = p->m->settings->total_philo - 1;
	while (!p->m->game_over)
	{
		pthread_mutex_lock(&p->m->queue_lock);
		if (fork_available(p) && p->id == p->m->queue[i])
		{
			take_forks(p);
			fork_unlock(p);
			pthread_mutex_unlock(&p->m->queue_lock);
			break ;
		}
		pthread_mutex_unlock(&p->m->queue_lock);
	}
}

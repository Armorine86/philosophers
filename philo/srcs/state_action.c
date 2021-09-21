/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state_action.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 13:29:21 by mmondell          #+#    #+#             */
/*   Updated: 2021/09/21 15:30:01 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	time_to_eat(t_philo *p)
{
	end_of_queue(p);
	gettimeofday(&p->time, NULL);
	p->last_meal = p->time;
	print_state(p, "is eating");
	sleep_timer(p->m->settings->time_eat);
	p->meal++;
	printf("Philo %d total meal is now at %d\n", p->id, p->meal);
	if (p->meal == p->m->settings->total_meals)
	{
		p->state = s_filled;
		return;
	}	
	drop_forks(p);
	p->state = s_sleep;
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
	while (true)
	{
		pthread_mutex_lock(&p->m->queue_lock);
		if (p->id == p->m->queue[i])
		{
			take_forks(p);
			p->state = s_eat;
			pthread_mutex_unlock(&p->m->queue_lock);	
			break;
		}
		pthread_mutex_unlock(&p->m->queue_lock);
	}
}

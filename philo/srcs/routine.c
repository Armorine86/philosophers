/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 09:23:24 by mmondell          #+#    #+#             */
/*   Updated: 2022/01/26 12:24:17 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	time_to_eat(t_philo *p)
{
	if (print_state(p, "is eating"))
		return ;
	sleep_timer(p, p->m->settings->time_eat);
	drop_forks(p);
	p->meal++;
	pthread_mutex_lock(&p->m->meal_lock);
	p->last_meal = time_now();
	if (p->meal == p->m->settings->total_meals)
		p->m->satiated++;
	pthread_mutex_unlock(&p->m->meal_lock);
	p->state = s_sleep;
}

void	time_to_sleep(t_philo *p)
{
	if (print_state(p, "is sleeping"))
		return ;
	sleep_timer(p, p->m->settings->time_sleep);
	p->state = s_think;
	if (print_state(p, "is thinking"))
		return ;
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
			pthread_mutex_unlock(&p->m->queue_lock);
			break ;
		}
		pthread_mutex_unlock(&p->m->queue_lock);
	}
}

void	*meal_routine(void *arg)
{
	t_philo	*p;

	p = (t_philo *)arg;
	while (!p->m->game_over)
	{
		if (p->state == s_think)
			prepare_to_eat(p);
		else if (p->state == s_eat)
			time_to_eat(p);
		else if (p->state == s_sleep)
			time_to_sleep(p);
	}
	return (NULL);
}

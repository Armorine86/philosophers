/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_state.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 14:52:00 by mmondell          #+#    #+#             */
/*   Updated: 2021/09/20 12:16:05 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

// void	print_state(t_philo *p, char *str)
// {
// 	pthread_mutex_lock(&p->m->print);
// 	if (p->state == s_die)
// 		printf("%ld philo %d died", p->m->clock - get_time(), p->id);
// 	else if (p->state == s_think)
// 		printf("%ld philo%d is thinking", p->m->clock, p->id);
// 	else if (p->state == s_eat)
// 		printf("%ld philo%d is eating", p->m->clock, p->id);
// 	else if (p->state == s_sleep)
// 		printf("%ld philo%d is sleeping", p->m->clock, p->id);
// 	pthread_mutex_unlock(&p->m->print);
// }

void	print_state(t_philo *p)
{
	pthread_mutex_lock(&p->m->print);
	if (p->fork == 1)
		printf("%ld Philo %d took his fork\n", clock_now(p), p->id);
	if (p->id != p->m->last_philo)
	{
		if (p->m->philo[p->id].fork == 1)
			printf("%ld Philo %d took philo %d's fork\n\n",clock_now(p), p->id, p->m->philo[p->id].id);
	}
	else
	{
		if (p->m->philo[0].fork == 1)
			printf("%ld Philo %d took philo %d's fork\n\n",clock_now(p), p->id, p->m->philo[0].id);
	}
	if (p->state == s_die)
		printf("%ld philo %d died\n", p->m->clock - get_time(), p->id);
	else if (p->state == s_think)
		printf("%ld philo %d is thinking\n",clock_now(p), p->id);
	else if (p->state == s_eat)
		printf("%ld philo %d is eating\n",clock_now(p), p->id);
	else if (p->state == s_sleep)
		printf("%ld philo %d is sleeping\n",clock_now(p), p->id);
	pthread_mutex_unlock(&p->m->print);
}

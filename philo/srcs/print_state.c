/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_state.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 14:52:00 by mmondell          #+#    #+#             */
/*   Updated: 2021/09/15 13:14:53 by mmondell         ###   ########.fr       */
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
	if (p->state == s_die)
		printf("%ld philo %d died", p->m->clock - get_time(), p->id);
	else if (p->state == s_think)
		printf("%ld philo%d is thinking", p->m->clock, p->id);
	else if (p->state == s_eat)
		printf("%ld philo%d is eating", p->m->clock, p->id);
	else if (p->state == s_sleep)
		printf("%ld philo%d is sleeping", p->m->clock, p->id);
	pthread_mutex_unlock(&p->m->print);
}

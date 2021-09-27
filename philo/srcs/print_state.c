/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_state.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 14:52:00 by mmondell          #+#    #+#             */
/*   Updated: 2021/09/27 11:38:03 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	print_state(t_philo *p, char *str)
{
	struct timeval	time;
	struct timeval	last_meal;

	pthread_mutex_lock(&p->m->print_lock);
	if (p->m->game_over == 1)
	{
		pthread_mutex_unlock(&p->m->print_lock);
		return ;
	}
	gettimeofday(&time, NULL);
	if (p->state == s_eat)
	{
		gettimeofday(&last_meal,NULL);
		p->last_meal = last_meal;
	}
	printf("\e[36m%-3ld\e[0m || \e[32mphilo \e[33m%d \e[32m%s\e[0m\n",
		   time_diff(p->m->clock, time), p->id, str);
	pthread_mutex_unlock(&p->m->print_lock);
}

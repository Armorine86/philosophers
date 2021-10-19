/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_state.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 14:52:00 by mmondell          #+#    #+#             */
/*   Updated: 2021/10/19 09:20:59 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	print_state(t_philo *p, char *str)
{
	unsigned long	current_time;

	current_time = time_now() - p->m->clock;
	pthread_mutex_lock(&p->m->print_lock);
	if (p->m->game_over == 1)
	{
		pthread_mutex_unlock(&p->m->print_lock);
		return ;
	}
	if (p->state == s_eat)
		p->last_meal = time_now();
	printf("\e[36m%-3ld\e[0m || \e[32mphilo \e[33m%d \e[32m%s\e[0m\n",
		current_time, p->id, str);
	pthread_mutex_unlock(&p->m->print_lock);
}

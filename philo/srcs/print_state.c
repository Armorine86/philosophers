/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_state.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 14:52:00 by mmondell          #+#    #+#             */
/*   Updated: 2021/09/21 15:29:31 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	print_state(t_philo *p, char *str)
{
	struct timeval	time;

	pthread_mutex_lock(&p->m->print_lock);
	gettimeofday(&time, NULL);
	printf("%ld philo %d %s\n", time_diff(p->m->clock, time), p->id, str);
	pthread_mutex_unlock(&p->m->print_lock);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 09:23:24 by mmondell          #+#    #+#             */
/*   Updated: 2021/09/13 09:25:10 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	*meal_routine(void *philo)
{
	t_info	*info;
	
	info = (t_info *)philo;
	pthread_mutex_lock(info->print);
	printf("Philo id: %d,  total philos: %d\n",info->id, info->settings->total_philo);
	printf("Philo id: %d,  time to die: %d\n",info->id, info->settings->time_die);
	printf("Philo id: %d,  time to eat: %d\n",info->id, info->settings->time_eat);
	printf("Philo id: %d,  time to sleep: %d\n",info->id, info->settings->time_sleep);
	pthread_mutex_unlock(info->print);
	return(info);
}
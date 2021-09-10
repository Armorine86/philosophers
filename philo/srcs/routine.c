/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 09:23:24 by mmondell          #+#    #+#             */
/*   Updated: 2021/09/10 09:43:35 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	*meal_routine(void *philo)
{
	t_info	*info;
	
	info = (t_info *)philo;
	pthread_mutex_lock(info->print);
	printf("total philos: %d\n", info->settings->total_philo);
	pthread_mutex_unlock(info->print);
	return(info);
}
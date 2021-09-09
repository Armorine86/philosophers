/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   meal_routine.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 08:22:49 by mmondell          #+#    #+#             */
/*   Updated: 2021/09/09 15:56:05 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*meal_routine(void	*philo)
{
	t_info	*info;
	int	i;

	i = 0;
	info = (t_info *)philo;
	pthread_mutex_lock(info->print);
	printf("total meals: %d\n", info->settings->total_meals);
	pthread_mutex_unlock(info->print);
	return (info);
}
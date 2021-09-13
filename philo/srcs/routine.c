/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 09:23:24 by mmondell          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2021/09/13 09:25:10 by mmondell         ###   ########.fr       */
=======
/*   Updated: 2021/09/10 15:18:03 by mmondell         ###   ########.fr       */
>>>>>>> 7cbea8ab59e9386527441a9755ba3fc62f309d0d
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	game_over(t_philo *philo)
{
	print_state(philo);
}

void	*meal_routine(void *arg)
{
	t_philo			*philo;
	
<<<<<<< HEAD
	info = (t_info *)philo;
	pthread_mutex_lock(info->print);
	printf("Philo id: %d,  total philos: %d\n",info->id, info->settings->total_philo);
	printf("Philo id: %d,  time to die: %d\n",info->id, info->settings->time_die);
	printf("Philo id: %d,  time to eat: %d\n",info->id, info->settings->time_eat);
	printf("Philo id: %d,  time to sleep: %d\n",info->id, info->settings->time_sleep);
	pthread_mutex_unlock(info->print);
	return(info);
=======
	philo = (t_philo *)arg;
	while (true)
	{
		if (philo->state[s_die] == 1)
			game_over(philo);
		else if (philo->state[s_think] == 1)
			;
		else if (philo->state[s_eat] == 1)
			;
		else if (philo->state[s_sleep] == 1)
			;
	}
	return(NULL);
>>>>>>> 7cbea8ab59e9386527441a9755ba3fc62f309d0d
}
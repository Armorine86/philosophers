/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 09:23:24 by mmondell          #+#    #+#             */
/*   Updated: 2021/09/13 09:43:52 by mmondell         ###   ########.fr       */
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
}
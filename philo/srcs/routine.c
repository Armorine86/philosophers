/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 09:23:24 by mmondell          #+#    #+#             */
/*   Updated: 2021/09/24 11:00:17 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

// *Function to continually check if philosopher is starving
// TODO create a mutex for the loop
// TODO create a condition to check if the game is over

void	*meal_routine(void *arg)
{
	t_philo	*p;

	p = (t_philo *)arg;
	while (!p->m->game_over)
	{
		if (p->state == s_think)
			prepare_to_eat(p);
		else if (p->state == s_eat)
			time_to_eat(p);
		else if (p->state == s_sleep)
			time_to_sleep(p);
		else if (p->state == s_filled)
			break ;
		else if (p->state == s_dead)
			break ;
	}
	drop_forks(p);
	return (NULL);
}

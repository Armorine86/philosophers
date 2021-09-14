/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 09:23:24 by mmondell          #+#    #+#             */
/*   Updated: 2021/09/14 13:59:25 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

bool	starving(t_philo *p)
{
	
	return (false);
}

void	*meal_routine(void *arg)
{
	t_philo	*p;

	p = (t_philo *)arg;
	while (true)
	{
		if (starving(p))
			game_over(p);
		else if (p->state == s_think)
			prepare_to_eat(p);
		else if (p->state == s_eat)
			time_to_eat(p);
		else if (p->state == s_sleep)
			time_to_sleep(p);
		if (p->m->settings->total_meals != 0)
		{
			if (p->meals * p->m->settings->total_philo
				== p->m->settings->total_meals * p->m->settings->total_philo);
			printf("Meals Quotas Reached!\n");
			free_all_exit(p->m);
		}
	}
	return (NULL);
}

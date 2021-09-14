/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 09:23:24 by mmondell          #+#    #+#             */
/*   Updated: 2021/09/14 15:25:14 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

bool	reached_meal_quotas(t_philo *p)
{
	int	i;
	int	total_philo;
	int	total_meals;

	total_meals = 0;
	total_philo = p->m->settings->total_philo;
	i = 0;
	while (i < total_philo)
	{
		total_meals += p[i].meals;
		i++;
	}
	if (total_meals == p->m->settings->total_meals)
		return (true);
	return (false);
}

void	*meal_routine(void *arg)
{
	t_philo	*p;

	p = (t_philo *)arg;
	while (true)
	{
		if (p->state == s_die)
		{
			printf("%ld philo %d has died\n", p->m->clock, p->id);
			break ;
		}
		else if (p->state == s_think)
			prepare_to_eat(p);
		else if (p->state == s_eat)
			time_to_eat(p);
		else if (p->state == s_sleep)
			time_to_sleep(p);
		if (reached_meal_quotas(p))
		{
			printf("Meal quotas reached!\n");
			break ;
		}
	}
	return (NULL);
}

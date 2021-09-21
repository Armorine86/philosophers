/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 09:23:24 by mmondell          #+#    #+#             */
/*   Updated: 2021/09/20 22:45:13 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

// *Function to continually check if philosopher is starving
// TODO create a mutex for the loop
// TODO create a condition to check if the game is over

/*bool	game_over(t_philo *p)
{
	while (true)
	{
		if (clock_now(p) - p->last_meal > p->m->settings->time_die)
			
	}
}*/

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
			printf("%ld philo %d has died\n",  clock_now(p), p->id);
			break ;
		}
		else if (p->state == s_think)
			prepare_to_eat(p);
		else if (p->state == s_eat)
			time_to_eat(p);
		else if (p->state == s_sleep)
			time_to_sleep(p);
		// if (reached_meal_quotas(p))
		// {
		// 	printf("Meal quotas reached!\n");
		// 	return (NULL);
		// }
	}
	return (NULL);
}

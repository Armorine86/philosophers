/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 09:23:24 by mmondell          #+#    #+#             */
/*   Updated: 2021/09/21 14:53:04 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

// *Function to continually check if philosopher is starving
// TODO create a mutex for the loop
// TODO create a condition to check if the game is over


// bool	reached_meal_quotas(t_philo *p)
// {
// 	int	quota;

// 	quota = p->m->settings->total_meals * p->m->settings->total_philo;
// 	if (p->m->meal_quota == quota)
// 		return (true);
// 	return (false);
// }

// bool	philo_is_starving(t_philo *p)
// {
// 	p->starve = time_diff(p);

// 	if (p->starve > p->m->settings->time_die)
// 		return (true);
// 	return (false);
// }

// void	*game_over(void	*arg)
// {
// 	t_philo	*p;

// 	p = (t_philo *)arg;
// 	while (true)
// 	{
// 		pthread_mutex_lock(&p->m->game_over);
// 		if (p->state == s_eat)
// 		{
// 			if (philo_is_starving(p))
// 			{
// 				printf("%ld STARVE\n", p->starve);
// 				printf("!!!!!******philo %d died******!!!!!\n", p->id);
// 				return (NULL);
// 			}
// 		}
// 		pthread_mutex_unlock(&p->m->game_over);
// 	}
// }

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
			break;
		else if (p->state == s_dead)
			break;
	}
	drop_forks(p);
	return (NULL);
}

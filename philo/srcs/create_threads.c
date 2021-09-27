/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_threads.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 09:13:47 by mmondell          #+#    #+#             */
/*   Updated: 2021/09/27 14:07:33 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	join_threads(pthread_t *t_id, pthread_t *death, int i)
{
	pthread_join(t_id[i], NULL);
	pthread_join(death[i], NULL);
}

void	free_mutex_and_pointers(t_main *m, int total_philo)
{
	int	i;

	i = 0;
	while (i < total_philo)
	{
		pthread_mutex_destroy(m->philo[i].fork_lock);
		free(m->philo[i].fork_lock);
		i++;
	}
	pthread_mutex_destroy(&m->print_lock);
	pthread_mutex_destroy(&m->queue_lock);
	pthread_mutex_destroy(&m->death_lock);
}

void	create_threads(t_main *m, int total_philo)
{
	pthread_t	*t_id;
	pthread_t	*death;
	int			i;

	t_id = ft_calloc(total_philo, sizeof(pthread_t));
	death = ft_calloc(total_philo, sizeof(pthread_t));
	if (!t_id)
		error_exit(m, 3);
	i = 0;
	while (i < total_philo)
	{
		if (pthread_create(&t_id[i], NULL, meal_routine, &m->philo[i]))
			error_exit(m, 4);
		if (pthread_create(&death[i], NULL, death_watch, &m->philo[i]))
			error_exit(m, 4);
		i++;
	}
	check_meal_quota(m, total_philo);
	while (i-- > 0)
		join_threads(t_id, death, i);
	free_mutex_and_pointers(m, total_philo);
	free(t_id);
	free(death);
}

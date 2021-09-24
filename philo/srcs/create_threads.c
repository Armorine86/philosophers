/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_threads.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 09:13:47 by mmondell          #+#    #+#             */
/*   Updated: 2021/09/24 10:38:39 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	free_mutex_and_pointers(t_main *m, int total_philo)
{
	int	i;

	i = total_philo;
	while (i < total_philo)
	{
		pthread_mutex_destroy(m->philo[i].fork_lock);
		free(m->philo[i].fork_lock);
		i++;
	}
	pthread_mutex_destroy(&m->print_lock);
	pthread_mutex_destroy(&m->queue_lock);
}

void	create_threads(t_main *m, int total_philo)
{
	pthread_t	*t_id;
	int			i;

	t_id = ft_calloc(total_philo, sizeof(pthread_t));
	if (!t_id)
		error_exit(m, 3);
	i = 0;
	while (i < total_philo)
	{
		if (pthread_create(&t_id[i], NULL, meal_routine, &m->philo[i]))
			error_exit(m, 4);
		i++;
	}
	death_watch(m);
	while (i-- > 0)
		pthread_join(t_id[i], NULL);
	free_mutex_and_pointers(m, total_philo);
	free(t_id);
}

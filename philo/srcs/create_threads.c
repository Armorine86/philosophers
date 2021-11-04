/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_threads.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 09:13:47 by mmondell          #+#    #+#             */
/*   Updated: 2021/11/04 15:09:08 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

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
	meal_quota_reached(m);
	while (i-- > 0)
		pthread_join(t_id[i], NULL);
	free_mutex_and_pointers(m, total_philo);
	free(t_id);
}

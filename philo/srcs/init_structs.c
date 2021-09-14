/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 09:08:52 by mmondell          #+#    #+#             */
/*   Updated: 2021/09/14 12:59:28 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	create_threads(t_main *m, int total_main)
{
	pthread_t	*t_id;
	int			i;

	t_id = (pthread_t *)malloc(sizeof(pthread_t) * total_main);
	if (!t_id)
		error_exit(m, 3);
	i = 0;
	while (i < total_main)
	{
		if (pthread_create(&t_id[i], NULL, &meal_routine, &m->philo[i]))
			error_exit(m, 4);
		i++;
	}
	pthread_mutex_destroy(&m->print);
	while (i-- > 0)
	{
		pthread_join(t_id[i], NULL);
		pthread_mutex_destroy(m->philo[i].fork_lock);
		free(m->philo[i].fork_lock);
	}
	free(t_id);
}

static bool	init_main_philo(t_main *m)
{
	int		i;

	i = 0;
	m->philo = ft_calloc(m->settings->total_philo, sizeof(t_philo));
	if (!m->philo)
		return (false);
	while (i < m->settings->total_philo)
	{
		m->philo[i].fork_lock = ft_calloc(m->settings->total_philo,
				sizeof(pthread_mutex_t));
		pthread_mutex_init(m->philo[i].fork_lock, NULL);
		m->philo[i].id = i + 1;
		m->philo[i].state = s_think;
		m->philo[i].priority = m->philo[i].id % 2;
		m->philo[i].m = m;
		i++;
	}
	i = 0;
	return (true);
}

static bool	init_settings(t_main *m, char **argv, int arg_count)
{
	t_settings	*settings;
	int			i;

	i = 0;
	settings = ft_calloc(1, sizeof(t_settings));
	if (!settings)
		return (false);
	settings->total_philo = ft_atoi(argv[i++]);
	settings->time_die = ft_atoi(argv[i++]);
	settings->time_eat = ft_atoi(argv[i++]);
	settings->time_sleep = ft_atoi(argv[i++]);
	settings->total_meals = 0;
	if (arg_count == 5)
		settings->total_meals = ft_atoi(argv[i]);
	m->settings = (t_settings *)settings;
	return (true);
}

t_main	*init_structs(char **argv, int count)
{
	t_main		*m;
	int			i;

	i = 0;
	m = ft_calloc(1, sizeof(t_main));
	m->clock = get_time();
	pthread_mutex_init(&m->print, NULL);
	if (!m || !init_settings(m, argv, count) || !init_main_philo(m))
		error_exit(m, 2);
	return (m);
}

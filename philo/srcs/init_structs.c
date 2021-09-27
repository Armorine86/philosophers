/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 09:08:52 by mmondell          #+#    #+#             */
/*   Updated: 2021/09/27 14:00:01 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

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
		gettimeofday(&m->philo[i].time, NULL);
		pthread_mutex_init(m->philo[i].fork_lock, NULL);
		m->philo[i].last_meal = m->philo[i].time;
		m->philo[i].id = i + 1;
		m->philo[i].priority = m->philo[i].id % 2;
		m->philo[i].state = s_think;
		m->philo[i].m = m;
		i++;
	}
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
	{
		settings->total_meals = ft_atoi(argv[i]);
		settings->meal_quota = 1;
	}
	m->settings = (t_settings *)settings;
	return (true);
}

t_main	*init_structs(char **argv, int count)
{
	struct timeval	time;
	t_main			*m;

	m = ft_calloc(1, sizeof(t_main));
	gettimeofday(&time, NULL);
	m->clock = time;
	pthread_mutex_init(&m->print_lock, NULL);
	pthread_mutex_init(&m->queue_lock, NULL);
	pthread_mutex_init(&m->death_lock, NULL);
	if (!m || !init_settings(m, argv, count) || !init_main_philo(m))
		error_exit(m, 2);
	m->queue = ft_calloc(m->settings->total_philo, sizeof(int));
	m->last_philo = m->settings->total_philo;
	m->total_priority = (m->settings->total_philo - 1) / 2;
	place_in_queue(m);
	return (m);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 09:08:52 by mmondell          #+#    #+#             */
/*   Updated: 2021/09/20 22:18:37 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	create_threads(t_main *m, int total_philo)
{
	pthread_t	*t_id;
	pthread_t	death_watch;
	int			i;

	t_id = ft_calloc(total_philo, sizeof(pthread_t));
	if (!t_id)
		error_exit(m, 3);
	i = 0;
	place_in_queue(m);
	print_stack(m->philo);
	while (i < total_philo)
	{
		pthread_create(&death_watch, NULL, game_over, &m->philo[i]);
		pthread_detach(death_watch);
		if (pthread_create(&t_id[i], NULL, meal_routine, &m->philo[i]))
			error_exit(m, 4);
		i++;
	}
	pthread_mutex_destroy(&m->print);
	pthread_mutex_destroy(&m->queue_lock);
	pthread_mutex_destroy(&m->print_stack);
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

	m = ft_calloc(1, sizeof(t_main));
	m->clock = get_time();
	pthread_mutex_init(&m->print, NULL);
	pthread_mutex_init(&m->queue_lock, NULL);
	pthread_mutex_init(&m->print_stack, NULL);
	if (!m || !init_settings(m, argv, count) || !init_main_philo(m))
		error_exit(m, 2);
	m->queue = ft_calloc((size_t)m->settings->total_philo, sizeof(int));
	m->last_philo = m->settings->total_philo;
	m->total_priority = (m->settings->total_philo - 1) / 2;
	return (m);
}

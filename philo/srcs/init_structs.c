/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 09:08:52 by mmondell          #+#    #+#             */
/*   Updated: 2021/09/10 15:18:25 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	create_threads(t_main *p, int total_main)
{
	pthread_t	*t_id;
	int			i;

	t_id = (pthread_t *)malloc(sizeof(pthread_t) * total_main);
	if (!t_id)
		error_exit(p, 3);
	i = 0;
	while (i < total_main)
	{
		if (pthread_create(&t_id[i], NULL, &meal_routine, &p->philo[i]))
			error_exit(p, 4);
		printf("Thread Id: %p\n", &t_id[i]);
		i++;
	}
	while (i-- > 0)
	{
		pthread_join(t_id[i], NULL);
		pthread_mutex_destroy(p->philo[i].fork_lock);
		pthread_mutex_destroy(p->philo[i].print);
		free(p->philo[i].fork_lock);
		free(p->philo[i].print);
	}
	free(t_id);
}

static bool	init_main_philo(t_main *p)
{
	t_philo	*philo;
	int		i;

	i = 0;
	philo = ft_calloc(0, sizeof(t_philo) * p->settings->total_philo);
	if (!philo)
		return (false);
	while (i < p->settings->total_philo)
	{
		philo[i].fork_lock = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t)
				* p->settings->total_philo);
		philo[i].print = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
		pthread_mutex_init(philo[i].print, NULL);
		pthread_mutex_init(philo[i].fork_lock, NULL);
		philo[i].id = i;
		philo[i].last_meal = philo->timer;
		philo[i].fork = 0;
		philo[i].state[s_think] = 1;
		//philo[i].settings = p->settings;
		i++;
	}
	i = 0;
	p->philo = (t_philo *)philo;
	return (true);
}

static bool	init_settings(t_main *p, char **argv, int arg_count)
{
	t_settings	*settings;
	int			i;

	i = 0;
	settings = ft_calloc(0, sizeof(t_settings));
	if (!settings)
		return (false);
	settings->total_philo = ft_atoi(argv[i++]);
	settings->time_die = ft_atoi(argv[i++]);
	settings->time_eat = ft_atoi(argv[i++]);
	settings->time_sleep = ft_atoi(argv[i++]);
	settings->total_meals = 0;
	if (arg_count == 5)
		settings->total_meals = ft_atoi(argv[i]);
	p->settings = (t_settings *)settings;
	return (true);
}

t_main	*init_structs(char **argv, int count)
{
	t_main		*p;
	int			main_num;
	int			i;

	i = 0;
	main_num = ft_atoi(argv[0]);
	p = ft_calloc(0, sizeof(t_main));
	if (!p || !init_settings(p, argv, count) || !init_main_philo(p))
		error_exit(p, 2);
	return (p);
}

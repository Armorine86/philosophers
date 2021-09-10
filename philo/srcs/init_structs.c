/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 09:08:52 by mmondell          #+#    #+#             */
/*   Updated: 2021/09/10 09:15:28 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	create_threads(t_philo *p, int total_philo)
{
	pthread_t	*t_id;
	int			i;

	t_id = (pthread_t *)malloc(sizeof(pthread_t) * total_philo);
	i = 0;
	while (i < total_philo)
	{
		printf("Before threads:  %d\n", p->info[i].settings->total_meals);
		if (pthread_create(&t_id[i], NULL, &meal_routine, &p->info[i]))
			error_exit(p, 3);
		printf("Thread Id: %p\n", &t_id[i]);
		i++;
	}
	while (i-- > 0)
	{
		pthread_join(t_id[i], NULL);
		pthread_mutex_destroy(p->info[i].fork_lock);
		pthread_mutex_destroy(p->info[i].print);
		free(p->info[i].fork_lock);
		free(p->info[i].print);
	}
}

static bool	init_philo_info(t_philo *p)
{
	t_info	*info;
	int		i;

	i = 0;
	info = ft_calloc(0, sizeof(t_info) * p->settings->total_philo);
	if (!info)
		return (false);
	while (i < p->settings->total_philo)
	{
		info[i].fork_lock = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t)
				* p->settings->total_philo);
		info[i].print = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
		pthread_mutex_init(info[i].print, NULL);
		pthread_mutex_init(info[i].fork_lock, NULL);
		info[i].id = i;
		info[i].timer = timer();
		info[i].fork = 0;
		info[i].state[s_think] = 1;
		info[i].settings = p->settings;
		i++;
	}
	i = 0;
	p->info = (t_info *)info;
	return (true);
}

static bool	init_settings(t_philo *p, char **argv, int arg_count)
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

t_philo	*init_structs(char **argv, int count)
{
	t_philo		*p;
	int			philo_num;
	int			i;

	i = 0;
	philo_num = ft_atoi(argv[0]);
	p = ft_calloc(0, sizeof(t_philo));
	if (!p || !init_settings(p, argv, count) || !init_philo_info(p))
		error_exit(p, 2);
	return (p);
}

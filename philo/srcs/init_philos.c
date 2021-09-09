/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 09:08:52 by mmondell          #+#    #+#             */
/*   Updated: 2021/09/09 11:24:41 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	create_threads(t_philo *p, int total_philo)
{
	pthread_t	thread_id[total_philo];
	int			i;
	
	i = 0;
	while (i < total_philo)
	{
		pthread_create(&thread_id[i], NULL, &meal_routine, &p[i]);
		i++;
	}
	while (i-- > 0)
	{
		pthread_join(thread_id[i], NULL);
		pthread_mutex_destroy(&p->info[i].fork_lock);
	}
}

void	init_philo_info(t_philo *p)
{
	t_info	*info;
	int	i;

	i = 0;
	info = ft_calloc(0, sizeof(t_info) * p->settings.total_philo);
	while (i < p->settings.total_philo)
	{
		info[i].id = i;
		info[i].timer = timer();
		info[i].state[s_think] = 1;
		i++;
	}
	i = 0;
	while (i < p->settings.total_philo)
		printf("Philo ID: %d\n", info[i++].id);
	p->info = (t_info *)info;
	free(info);
}

void	init_settings(t_philo *p, char **argv, int arg_count)
{
	int	i;

	i = 0;
	p->settings.total_philo = ft_atoi(argv[i++]);
	p->settings.time_die = ft_atoi(argv[i++]);
	p->settings.time_eat = ft_atoi(argv[i++]);
	p->settings.time_sleep = ft_atoi(argv[i++]);
	if (arg_count == 5)
		p->settings.total_meals = ft_atoi(argv[i]);
}

t_philo	*init_structs(char **argv, int *error, int count)
{
	t_philo		*p;
	int			philo_num;
	int			i;

	i = 0;
	philo_num = ft_atoi(argv[0]);
	p = ft_calloc(0, sizeof(t_philo));
	init_settings(p, argv, count);
	if (!p)
		*error = 2;
	init_philo_info(p);
	p->info[4].id = 99999;
	while (i < p->settings.total_philo)
		printf("Philo ID: %d\n", p->info[i++].id);
	return (p);
}

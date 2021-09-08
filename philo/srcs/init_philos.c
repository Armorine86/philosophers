/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 09:08:52 by mmondell          #+#    #+#             */
/*   Updated: 2021/09/08 15:53:26 by mmondell         ###   ########.fr       */
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
		pthread_join(thread_id[i], NULL);
}



t_info	*init_philo_info(t_philo *p)
{
	t_info	*info;
	int	i;

	info = ft_calloc(0, sizeof(t_info) * p->settings->total_philo);
	i = 0;
	while (i < p->settings->total_philo)
	{
		info[i].id = i;
		info[i].state[s_think] = 1;
		info[i].timer = timer();
		i++;
	}
	return (info);
}

t_settings	*init_settings(char **argv, int arg_count)
{
	t_settings	*s;
	int	i;

	s = ft_calloc(0, sizeof(t_settings));
	i = 0;
	s->total_philo = ft_atoi(argv[i++]);
	s->time_die = ft_atoi(argv[i++]);
	s->time_eat = ft_atoi(argv[i++]);
	s->time_sleep = ft_atoi(argv[i++]);
	if (arg_count == 5)
		s->total_meals = ft_atoi(argv[i]);
	return (s);
}

t_philo	*init_structs(char **argv, int *error, int count)
{
	t_info		*info;
	t_settings	*s;
	t_philo		*p;
	int			philo_num;
	int			i;

	i = 0;
	philo_num = ft_atoi(argv[0]);
	p = ft_calloc(0, sizeof(t_philo) * philo_num);
	s = init_settings(argv, count);
	p->settings = (t_settings *)s;
	free(s);
	if (!p)
		*error = 2;
	info = init_philo_info(p);
	p->info = (t_info *)info;
	return (p);
}

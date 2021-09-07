/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 09:08:52 by mmondell          #+#    #+#             */
/*   Updated: 2021/09/07 12:43:34 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_settings	*init_settings(char **argv, int arg_count)
{
	t_settings	*s;
	int			i;

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

t_philo	*init_philos(char **argv, int arg_count, int *error)
{
	t_philo		*p;
	t_settings	*s;
	
	int		philo_num;
	int		i;
	i = 1;
	philo_num = ft_atoi(argv[0]);
	p = ft_calloc(0, sizeof(t_philo) * philo_num);
	s = init_settings(argv, arg_count);
	if (!p || !s)
		*error = 2;
	while (i <= philo_num)
	{
		p[i].info.id = i;
		p[i].info.state[s_think] = 1;
		p[i].info.clock = timer();
		printf("philo id: %d time: %lld \n", p[i].info.id, p[i].info.clock);
		i++;
	}
	return (p);
}

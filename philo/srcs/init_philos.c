/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 09:08:52 by mmondell          #+#    #+#             */
/*   Updated: 2021/09/03 17:51:09 by mmondell         ###   ########.fr       */
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

bool	init_philos(t_philo *p, char **argv, int arg_count, int *error)
{
	unsigned int	i;

	i = 1;
	p = ft_calloc(0, sizeof(t_philo) * i);
	p->config = init_settings(argv, arg_count);
	if (!p || !p->config)
		*error = 2;
	while (i <= p->config->total_philo)
	{
		p[i].id = i;
		i++;
	}
	return (true);
}

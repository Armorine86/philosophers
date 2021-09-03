/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 09:08:52 by mmondell          #+#    #+#             */
/*   Updated: 2021/09/03 12:41:29 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	init_philos(t_philo *p, char **argv)
{
	int		i;

	i = ft_atoi(argv[0]);
	p = malloc(sizeof(t_philo) * i);
	if (!p)
		return (false);
	//while (i > 0)
	//	init_settings(p, i);
	return (true);
}
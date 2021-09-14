/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 09:55:45 by mmondell          #+#    #+#             */
/*   Updated: 2021/09/14 08:31:38 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

long	get_time(void)
{
	struct timeval	time;
	long			s1;
	long			s2;

	gettimeofday(&time, NULL);
	s1 = time.tv_sec * 1000;
	s2 = time.tv_usec / 1000;
	return (s1 + s2);
}

void	free_all_exit(t_main *m)
{
	free(m->philo);
	free(m->settings);
	free(m);
	exit(0);
}

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	if (tab)
	{
		while (tab[i])
			free(tab[i++]);
		free(tab);
	}
}

void	error_exit(t_main *p, int error)
{
	if (error == 1)
		ft_putstr_fd("INVALID ARGUMENT", 2);
	else if (error == 2)
		ft_putstr_fd("MALLOC FAILED", 2);
	else if (error == 3)
	{
		ft_putstr_fd("THREAD MALLOC FAILED", 2);
		free_all_exit(p);
	}
	else if (error == 4)
	{
		ft_putstr_fd("THREAD CREATION FAILED", 2);
		free_all_exit(p);
	}
}

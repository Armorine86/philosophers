/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 09:55:45 by mmondell          #+#    #+#             */
/*   Updated: 2021/09/08 14:43:35 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

unsigned int	timer(void)
{
	struct timeval	time;
	unsigned int	s1;
	unsigned int	s2;

	gettimeofday(&time, NULL);
	s1 = time.tv_sec * 1000;
	s2 = time.tv_usec / 1000;
	return (s1 + s2);
}

void	free_all_exit(t_philo *p)
{
	free(p->fork_mutex);
	free(p);
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

void	error_exit(int error)
{
	if (error == 1)
		ft_putstr_fd("INVALID ARGUMENT", 2);
	else if (error == 2)
		ft_putstr_fd("MALLOC FAILED", 2);
	exit (EXIT_FAILURE);
}

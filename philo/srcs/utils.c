/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 09:55:45 by mmondell          #+#    #+#             */
/*   Updated: 2021/11/03 13:06:57 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	free_all_exit(t_main *m)
{
	free(m->philo);
	free(m->settings);
	free(m->queue);
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
	{
		ft_putstr_fd("INVALID ARGUMENT\n", 2);
		exit(EXIT_FAILURE);
	}
	else if (error == 2)
		ft_putstr_fd("MALLOC FAILED\n", 2);
	else if (error == 3)
	{
		ft_putstr_fd("THREAD MALLOC FAILED\n", 2);
		free_all_exit(p);
	}
	else if (error == 4)
	{
		ft_putstr_fd("THREAD CREATION FAILED\n", 2);
		free_all_exit(p);
	}
}

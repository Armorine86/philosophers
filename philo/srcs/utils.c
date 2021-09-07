/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 09:55:45 by mmondell          #+#    #+#             */
/*   Updated: 2021/09/07 12:49:13 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int64_t	timer(void)
{
	struct timeval	time;
	int64_t			s1;
	int64_t			s2;
		
	gettimeofday(&time, NULL);
	s1 = (int64_t)time.tv_sec / 1000;
	s2 = time.tv_usec * 1000;
	return(s1 + s2);
}

void	free_all_exit(t_philo *p)
{
	free(p);
}

void	free_tab(char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
		free(argv[i++]);
	free(argv);
}

void	error_exit(int error)
{
	if (error == 1)
		ft_putstr_fd("INVALID ARGUMENT", 2);
	else if (error == 2)
		ft_putstr_fd("MALLOC FAILED", 2);
	exit (EXIT_FAILURE);
}

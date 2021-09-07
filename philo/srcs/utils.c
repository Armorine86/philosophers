/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 09:55:45 by mmondell          #+#    #+#             */
/*   Updated: 2021/09/03 17:59:15 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "utils.h"

void	free_all_exit(t_philo **f)
{
	free((*f)->config);
	free((*f));
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

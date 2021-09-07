/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 13:54:43 by mmondell          #+#    #+#             */
/*   Updated: 2021/09/03 17:58:02 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>
# include <stdio.h>
# include <stdbool.h>
# include <stdlib.h>
# include <unistd.h>
# include "utils.h"

enum e_state
{
	e_sleep,
	e_think,
	e_eat,
	e_die,
};

typedef struct s_settings
{
	unsigned int	total_philo;
	unsigned int	time_eat;
	unsigned int	time_sleep;
	unsigned int	time_die;
	unsigned int 	total_meals;
}	t_settings;

typedef struct s_philo
{
	unsigned int	id;
	unsigned int	clock;
	int				state[4];
	t_settings		*config;
}	t_philo;

bool	init_philos(t_philo *p, char **argv, int argc, int *error);

/* UTILITIES */

void	error_exit(int error);
void	free_all_exit(t_philo **f);
void	free_tab(char **argv);

#endif
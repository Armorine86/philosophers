/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 15:44:20 by mmondell          #+#    #+#             */
/*   Updated: 2021/09/13 09:25:34 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHER_H
# define PHILOSOPHER_H

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
	s_eat,
	s_sleep,
	s_think,
	s_die,
};

typedef struct s_settings
{
	int				total_philo;
	int				total_meals;
	unsigned int	time_die;
	unsigned int	time_eat;
	unsigned int	time_sleep;
}	t_settings;

typedef struct s_info
{
	pthread_mutex_t	*fork_lock;
	pthread_mutex_t	*print;
	unsigned int	timer;
	unsigned int	last_meal;
	int				fork;
	int				id;
	int				state[4];
	t_settings		*settings;
}	t_info;

typedef struct s_philo
{
	t_settings			*settings;
	t_info				*info;
}	t_philo;

t_philo			*init_structs(char **argv, int count);
void			*meal_routine(void	*philo);
void			create_threads(t_philo *p, int total_philo);

/* UTILITIES */

void			error_exit(t_philo *p, int error);
void			free_all_exit(t_philo *p);
void			free_tab(char **argv);
unsigned int	timer(void);

#endif
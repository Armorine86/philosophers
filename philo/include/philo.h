/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 15:44:20 by mmondell          #+#    #+#             */
/*   Updated: 2021/09/08 15:53:37 by mmondell         ###   ########.fr       */
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
	s_sleep,
	s_think,
	s_eat,
	s_die,
};

// typedef struct s_mutex
// {
	
// }	t_mutex;
typedef struct s_settings
{
	int				total_philo;
	unsigned int	time_die;
	unsigned int	time_eat;
	unsigned int	time_sleep;
	unsigned int	total_meals;
}	t_settings;

typedef struct s_info
{
	unsigned int	timer;
	unsigned int	last_meal;
	int				fork;
	int				id;
	int				state[4];
}	t_info;

typedef struct s_philo
{
	t_settings			*settings;
	t_info				*info;
	pthread_mutex_t		*fork_mutex;
	int					left_fork;
	int					right_fork;	
}	t_philo;

t_settings		*init_settings(char **argv, int arg_count);
t_philo			*init_structs(char **argv, int *error, int count);
void			init_mutex(t_philo *p);
void			*meal_routine(void	*philo);
void			create_threads(t_philo *p, int total_philo);

/* UTILITIES */

void			error_exit(int error);
void			free_all_exit(t_philo *p);
void			free_tab(char **argv);
unsigned int	timer(void);

#endif
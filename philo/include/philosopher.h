/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 15:44:20 by mmondell          #+#    #+#             */
/*   Updated: 2021/09/14 13:34:38 by mmondell         ###   ########.fr       */
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

typedef enum e_state
{
	s_eat,
	s_sleep,
	s_think,
	s_die,
} t_state;

typedef struct s_settings
{
	int	total_philo;
	int	total_meals;
	int	time_die;
	int	time_eat;
	int	time_sleep;
}	t_settings;

typedef struct s_philo
{
	pthread_mutex_t	*fork_lock;
	long			last_meal;
	long			start_eat;
	int				meals;
	int				satiated;
	int				priority;
	int				fork;
	int				id;
	t_state			state;
	struct s_main	*m;
}	t_philo;

typedef struct s_main
{
	t_settings			*settings;
	t_philo				*philo;
	struct timeval		*clock;
	pthread_mutex_t		print;
}	t_main;

/* MAIN */

t_main			*init_structs(char **argv, int count);
void			create_threads(t_main *m, int total_main);

/* ROUTINE */

void			print_state(t_philo *philo);
void			*meal_routine(void	*main);
void			prepare_to_eat(t_philo *p);
void			time_to_sleep(t_philo *p);
void			time_to_eat(t_philo *p);



/* UTILITIES */

void			error_exit(t_main *m, int error);
void			free_all_exit(t_main *m);
void			free_tab(char **argv);
long			get_time(void);

#endif
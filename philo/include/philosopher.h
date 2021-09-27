/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 15:44:20 by mmondell          #+#    #+#             */
/*   Updated: 2021/09/27 15:06:15 by mmondell         ###   ########.fr       */
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

# define UL unsigned long

typedef enum e_state
{
	s_eat,
	s_sleep,
	s_think,
	s_full,
}	t_state;

typedef struct s_settings
{
	int		total_philo;
	int		total_meals;
	int		meal_quota;
	long	time_die;
	long	time_eat;
	long	time_sleep;
}	t_settings;

typedef struct s_philo
{
	pthread_mutex_t	*fork_lock;
	struct timeval	last_meal;
	struct timeval	time;
	struct s_main	*m;
	int				full;
	int				priority;
	int				meal;
	int				fork;
	int				id;
	t_state			state;
}	t_philo;

typedef struct s_main
{
	int				game_over;
	int				last_philo;
	int				total_priority;
	int				*queue;
	t_philo			*philo;
	t_settings		*settings;
	struct timeval	clock;
	pthread_mutex_t	death_lock;
	pthread_mutex_t	queue_lock;
	pthread_mutex_t	print_lock;
}	t_main;

/* MAIN */

t_main			*init_structs(char **argv, int count);
void			create_threads(t_main *m, int total_main);

/* ROUTINE */

void			place_in_queue(t_main *m);
void			end_of_queue(t_philo *p);
void			print_state(t_philo *p, char *str);
void			*meal_routine(void	*main);
void			prepare_to_eat(t_philo *p);
void			time_to_sleep(t_philo *p);
void			time_to_eat(t_philo *p);
void			*death_watch(void *arg);
void			check_meal_quota(t_main *m, int total_philo);

/* ROUTINE UTILS */

bool			check_if_starving(t_philo *p);
bool			fork_available(t_philo *p);
void			take_forks(t_philo *p);
void			drop_forks(t_philo *p);
void			fork_unlock(t_philo *p);

/* TIME UTILITIES */

unsigned long	time_diff(struct timeval first, struct timeval second);
void			sleep_timer(long milliseconds);

/* UTILITIES */

void			error_exit(t_main *m, int error);
void			free_all_exit(t_main *m);
void			free_tab(char **argv);

#endif

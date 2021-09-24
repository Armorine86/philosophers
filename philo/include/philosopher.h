/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 15:44:20 by mmondell          #+#    #+#             */
/*   Updated: 2021/09/24 10:57:42 by mmondell         ###   ########.fr       */
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
	s_dead,
	s_filled,
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
	long			starve;
	int				priority;
	int				meal;
	int				fork;
	int				id;
	t_state			state;
	struct s_main	*m;
}	t_philo;

typedef struct s_main
{
	struct timeval	clock;
	int				game_over;
	int				last_philo;
	int				total_priority;
	int				*queue;
	t_settings		*settings;
	t_philo			*philo;
	pthread_mutex_t	queue_lock;
	pthread_mutex_t	print_lock;
}	t_main;

/* MAIN */

t_main			*init_structs(char **argv, int count);
void			create_threads(t_main *m, int total_main);

/* ROUTINE */

void			*game_over(void	*arg);
void			place_in_queue(t_main *m);
void			end_of_queue(t_philo *p);
void			print_state(t_philo *p, char *str);
void			*meal_routine(void	*main);
void			prepare_to_eat(t_philo *p);
void			time_to_sleep(t_philo *p);
void			time_to_eat(t_philo *p);
void			death_watch(t_main *m);

/* ROUTINE UTILS */

bool			check_if_starving(t_philo *p);
bool			fork_available(t_philo *p);
void			take_forks(t_philo *p);
void			drop_forks(t_philo *p);

/* TIME UTILITIES */

unsigned long	time_diff(struct timeval first, struct timeval second);
void			sleep_timer(long milliseconds);
long			get_time(struct timeval *time);
long			get_time(struct timeval *time);

/* UTILITIES */

void			error_exit(t_main *m, int error);
void			free_all_exit(t_main *m);
void			free_tab(char **argv);

void			print_stack(t_philo *p);

#endif

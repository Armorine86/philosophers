/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 15:44:20 by mmondell          #+#    #+#             */
/*   Updated: 2021/11/04 09:20:27 by mmondell         ###   ########.fr       */
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

# define DEAD "\e[31m\e[40mdied\e[0m 💀"
# define PRINT_MSG "\e[36m%-3ld\e[0m || \e[32mphilo \e[33m%d \e[32m%s\e[0m\n"
# define QUOTA_MSG "\e[95m\e[4mAll Philos Reached The Meal Quota!\e[0m\n"

typedef enum e_state
{
	s_eat,
	s_sleep,
	s_think,
	s_full,
	s_dead,
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
	struct s_main	*m;
	long			last_meal;
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
	int				satiated;
	int				*queue;
	long			clock;
	t_philo			*philo;
	t_settings		*settings;
	pthread_mutex_t	meal_lock;
	pthread_mutex_t	queue_lock;
	pthread_mutex_t	print_lock;
	pthread_mutex_t	death_lock;

}	t_main;

/* MAIN */

t_main			*init_structs(char **argv, int count);
void			create_threads(t_main *m, int total_main);

/* ROUTINE */

void			*meal_routine(void	*main);
void			*death_watch(void *arg);
void			prepare_to_eat(t_philo *p);
void			time_to_sleep(t_philo *p);
void			time_to_eat(t_philo *p);

/* ROUTINE UTILS */

bool			philo_is_dead(t_philo *p);
bool			check_if_starving(t_philo *p);
bool			fork_available(t_philo *p);
void			meal_quota_reached(t_main *m);
int				print_state(t_philo *p, char *str);
void			end_of_queue(t_philo *p);
void			place_in_queue(t_main *m);
void			take_forks(t_philo *p);
void			drop_forks(t_philo *p);
void			fork_unlock(t_philo *p);

/* TIME UTILITIES */

long			time_now(void);
void			sleep_timer(t_philo *p, long param);

/* UTILITIES */

void			error_exit(t_main *m, int error);
void			free_all_exit(t_main *m);
void			free_tab(char **argv);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 08:22:20 by mmondell          #+#    #+#             */
/*   Updated: 2021/09/17 12:36:41 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	print_stack(t_philo *p)
{
	int	i;

	i = 0;
	pthread_mutex_lock(&p->m->print);
	printf("THIS IS PHILO %d\n", p->id);
	while (i < p->m->settings->total_philo)
	{
		printf("STACK[%d]  %d\n", i, p->m->queue[i]);
		i++;
	}
	ft_putchar_fd(1, '\n');
	sleep(1);
	pthread_mutex_unlock(&p->m->print);
}

bool	already_in_queue(t_philo *p)
{
	int	i;

	i = 0;
	while (i < p->m->settings->total_philo)
	{
		if (p->m->queue[i] == p->id)
			return (true);
		i++;
	}
	return (false);
}

bool	queue_is_full(t_philo *p)
{
	int	i;

	i = 0;
	while (i < p->m->settings->total_philo)
	{
		if (p->m->queue[i] == 0)
			return (false);
		i++;
	}
	return (true);
}

void	pop_next_in_queue(t_philo *p)
{
	int	i;
	int	j;
	int	temp;

	i = p->m->settings->total_philo - 1;
	temp = p->m->queue[i];
	j = 2;
	while (j > 0)
	{
		temp = p->m->queue[i];
		p->m->queue[i] = p->m->queue[i - 1];
	}
}

void	place_philo(t_philo *p, int	priority)
{
	int	i;

	i = p->m->settings->total_philo - 1; 
	if (p->id == p->m->last_philo)
		p->m->queue[0] = p->id;
	else if (p->priority == priority && p->id != p->m->last_philo)
	{
		if (p->m->queue[i] == 0)
			p->m->queue[i] = p->id;
		else
		{
			while (p->m->queue[i] != 0)
				i--;
			p->m->queue[i] = p->id;
		}
	}
}

void	place_philos(t_philo *p)
{
	int	i;
	int	total_priority;

	total_priority = (p->m->settings->total_philo - 1) / 2;
	i = 1;
	if (p->id == p->m->last_philo)
		p->m->queue[0] = p->id;
	else if (p->priority == 0)
	{
		while (p->m->queue[i] != 0)
			i++;
		p->m->queue[i] = p->id;
		i = 1;
	}
	else 
	{
		i += total_priority;
		while (p->m->queue[i] != 0)
			i++;
		p->m->queue[i] = p->id;
		i = 1;
	}
}

void	get_in_queue(t_philo *p)
{
	pthread_mutex_lock(&p->m->queue_lock);
	while (!already_in_queue(p))
		place_philos(p);
	pthread_mutex_unlock(&p->m->queue_lock);
	while (true)
		;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 08:22:20 by mmondell          #+#    #+#             */
/*   Updated: 2021/09/17 14:54:55 by mmondell         ###   ########.fr       */
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


void	end_of_queue(t_philo *p)
{
	int	i;
	int	tmp;

	i = p->m->settings->total_philo - 1;
	tmp = p->m->queue[i];
	while (i >= 0)
	{
		p->m->queue[i] = p->m->queue[i - 1];
		--i;
	}
	p->m->queue[0] = tmp;
}

void	place_philos(t_philo *p, int total_priority)
{
	int	i;
	int	j;

	j = 1;
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
		j += total_priority;
		while (p->m->queue[j] != 0)
			j++;
		p->m->queue[j] = p->id;
		j = 1;
	}
}

void	pop_from_queue(t_philo *p)
{
	int	i;

	i = p->m->settings->total_philo - 1;
	while (p->id == p->m->queue[i])
	{
		if (p->id == p->m->queue[i])
		{
			end_of_queue(p);
			prepare_to_eat(p);
		}
		else if (p->m->queue[i] == p->m->last_philo)
		{
			end_of_queue(p);
			prepare_to_eat(p);
			return ;
		}
		else
		{
			usleep(50 * 1000);
			continue;
		}
	}
}

void	get_in_queue(t_philo *p)
{
	int	total_priority;

	total_priority = (p->m->settings->total_philo - 1) / 2;
	while (!already_in_queue(p))
		place_philos(p, total_priority);
}

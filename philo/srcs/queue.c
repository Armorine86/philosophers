/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 08:22:20 by mmondell          #+#    #+#             */
/*   Updated: 2021/09/21 09:17:23 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

/*void	print_stack(t_philo *p)
{
	int	i;

	pthread_mutex_lock(&p->m->print_stack);
	i = 0;
	printf("THIS IS PHILO %d\n", p->id);
	while (i < p->m->settings->total_philo)
	{
		printf("STACK[%d]  %d\n", i, p->m->queue[i]);
		i++;
	}
	ft_putchar_fd(1, '\n');
	pthread_mutex_unlock(&p->m->print_stack);
}*/

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

void	place_in_queue(t_main *m)
{
	int	i;
	int	j;

	j = 1;
	i = 0;
	while (i < m->settings->total_philo)
	{
		j = 1;
		if (m->philo[i].id == m->last_philo)
			m->queue[0] = m->philo[i].id;
		else if (m->philo[i].priority == 0)
		{
			while (m->queue[j] != 0)
				j++;
			m->queue[j] = m->philo[i].id;
		}
		else
		{
			j += m->total_priority;
			while (m->queue[j] != 0)
				j++;
			m->queue[j] = m->philo[i].id;
		}
		i++;
	}
}

void	end_of_queue(t_philo *p)
{
	int i;
	int tmp;

	i = p->m->settings->total_philo - 1;
	tmp = p->m->queue[i];
	while (i >= 0)
	{
		p->m->queue[i] = p->m->queue[i - 1];
		--i;
	}
	p->m->queue[0] = tmp;
}

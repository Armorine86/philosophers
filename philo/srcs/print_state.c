/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_state.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 14:52:00 by mmondell          #+#    #+#             */
/*   Updated: 2021/09/14 15:26:29 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	print_state(t_philo *p)
{
	if (p->state == s_die)
	{
		printf("%ld philo %d died", p->m->clock, p->id);
		free_all_exit(p->m);
	}
	else if (p->state == s_think)
		printf("%ld philo%d is thinking", p->m->clock, p->id);
	else if (p->state == s_eat)
		printf("%ld philo%d is eating", p->m->clock, p->id);
	else if (p->state == s_sleep)
		printf("%ld philo%d is sleeping", p->m->clock, p->id);
}

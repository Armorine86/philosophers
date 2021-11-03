/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_over.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 14:37:48 by mmondell          #+#    #+#             */
/*   Updated: 2021/11/03 13:53:35 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

bool	meal_quota_reached(t_philo *p)
{
	if (p->m->settings->meal_quota == 0)
		return (false);
	if (p->m->satiated == p->m->settings->total_philo)
	{
		p->m->game_over = 1;
		printf(QUOTA_MSG);
		return (true);
	}
	return (false);
}

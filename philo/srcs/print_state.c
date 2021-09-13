/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_state.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 14:52:00 by mmondell          #+#    #+#             */
/*   Updated: 2021/09/10 15:17:36 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	print_state(t_philo *philo)
{
	if (philo->state[s_think] == 1)
		printf("%d philo%d is thinking", philo->timer, philo->id);
	else if (philo->state[s_eat] == 1)
		printf("%d philo%d is eating", philo->timer, philo->id);
	else if (philo->state[s_sleep] == 1)
		printf("%d philo%d is sleeping", philo->timer, philo->id);
	if (philo->state[s_die] == 1)
		printf("%d philo%d died", philo->timer, philo->id);
}
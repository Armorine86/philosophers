/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 13:54:41 by mmondell          #+#    #+#             */
/*   Updated: 2021/09/02 16:12:56 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	usage(void)
{
	ft_putstr("\n\033[31m-------------------\n");
	ft_putstr("|MISSING ARGUMENTS|\n");
	ft_putstr("-------------------\n");
	ft_putstr("\n\033[33mYou need at least 4 arguments.\n");
	ft_putstr("\n\033[34m./philosopher ");
	ft_putstr("[total_philosophers] [time to die] ");
	ft_putstr("[time to eat] [time to sleep] [total meals(OPTIONAL)]\n\n");
	exit (0);
}

int	main(int argc, char **argv)
{
	if (argc < 4)
		usage();
	argv++;
	return (0);
}
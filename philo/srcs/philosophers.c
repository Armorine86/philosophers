/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 13:54:41 by mmondell          #+#    #+#             */
/*   Updated: 2021/09/03 11:05:17 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	error_exit(void)
{
	
}

void	usage(char *argv)
{
	printf("\033[31m ------------------- \n");
	printf("| MISSING ARGUMENTS |\n");
	printf(" ------------------- \033[0m\n\n");
	printf("\033[33m At least 4 arguments are needed\033[34m\n\n");
	printf("%s", argv);
	printf(" [total_Philos] [Time to die]");
	printf(" [Time to eat] [Time to sleep]");
	printf(" [(OPTIONAL) Number of meals]\033[0m\n");
	printf("\n\033[35m**Arguments are in milliseconds");
	printf(" I.E: 200 milliseconds = 2 seconds**\n");
	printf("Values must be greater than 0\n");
}

int	main(int argc, char **argv)
{
	t_philo philo;
	
	if (argc < 4)
		usage(argv[0]);
	argv++;
	if (argc == 2)
		argv = ft_split(argv[1], ' ');
	if (!init_philos(&philo, argv))
		error_exit();
	return (0);
}
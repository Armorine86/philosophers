/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 13:54:41 by mmondell          #+#    #+#             */
/*   Updated: 2021/11/08 09:32:23 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

bool	check_args(char **argv)
{
	int	i;
	int	j;

	i = 0;
	while (argv[i])
	{
		if (ft_atoi(argv[i]) <= 0)
			return (false);
		j = 0;
		if (argv[i][j] == '+')
			j++;
		while (argv[i][j])
		{
			if (!ft_isdigit(argv[i][j]))
				return (false);
			j++;
		}
		i++;
	}
	return (true);
}

char	**split_argv(char *str, int *free_me)
{
	char	**ret;

	ret = ft_split(str, ' ');
	*free_me = 1;
	return (ret);
}

int	get_parameters_count(int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc > 2)
		i = argc - 1;
	else
	{
		while (argv[i])
			i++;
	}
	return (i);
}

void	usage(void)
{
	printf("\033[31m ------------------- \n");
	printf("| MISSING ARGUMENTS |\n");
	printf(" ------------------- \033[0m\n\n");
	printf("\033[33m At least 4 arguments are needed\033[34m\n\n");
	printf("./philo");
	printf(" [total_Philos] [Time to die]");
	printf(" [Time to eat] [Time to sleep]");
	printf(" [(OPTIONAL) Number of meals]\033[0m\n");
	printf("\n\033[35m**Arguments are in milliseconds");
	printf(" I.E: 200 milliseconds = 2 seconds**\n");
	printf("Values must be greater than 1\n");
}

int	main(int argc, char **argv)
{
	t_main		*m;
	int			count;	
	int			free_me;

	m = NULL;
	free_me = 0;
	argv++;
	if (argc == 2)
		argv = split_argv(argv[0], &free_me);
	count = get_parameters_count(argc, argv);
	if (count < 4 || count > 5)
	{
		usage();
		exit(EXIT_FAILURE);
	}
	if (!check_args(argv))
		error_exit(m, 1);
	m = init_structs(argv, count);
	count = ft_atoi(argv[0]);
	create_threads(m, count);
	if (free_me)
		free_tab(argv);
	free_all_exit(m);
}

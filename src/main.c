/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flmarsou <flmarsou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 12:31:14 by flmarsou          #+#    #+#             */
/*   Updated: 2024/09/18 14:49:07 by flmarsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	init_stats(t_philo *philo, int argc, const char **argv)
{
	philo->stats.nbr_of_philos = ft_atou(argv[1]);
	philo->stats.time_to_die = ft_atou(argv[2]);
	philo->stats.time_to_eat = ft_atou(argv[3]);
	philo->stats.time_to_sleep = ft_atou(argv[4]);
	if (argc == 6)
		philo->stats.cycles = ft_atou(argv[5]);
	else
		philo->stats.cycles = 0;
}

int	main(int argc, const char **argv)
{
	t_philo	*philo;

	if (!check_argv(argv) || !check_argc(argc))
	{
		printf("\e[1;35m[!] - Usage: \e[1;97m");
		printf("<nbr_of_philo> <time_to_die> <time_to_eat> ");
		printf("<time_to_sleep> <nbr_of_cycles>\n\e[0m");
		exit(1);
	}
	philo = (t_philo *)malloc(sizeof(t_philo));
	init_stats(philo, argc, argv);
	free(philo);
	return (0);
}

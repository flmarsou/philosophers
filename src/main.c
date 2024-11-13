/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flmarsou <flmarsou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 12:31:14 by flmarsou          #+#    #+#             */
/*   Updated: 2024/11/13 14:12:39 by flmarsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static void	print_top(void)
{
	printf("╔══════════╦══════════╦══════════════════╗\n");
	printf("║ \e[1mTime\e[0m     ║ \e[1mPhilo\e[0m    ║");
	printf(" \e[1mEvent\e[0m            ║\n");
	printf("╠══════════╬══════════╬══════════════════╣\n");
}

// Creates a thread for each philosopher to run the routine function.
// Waits for each philosopher thread to finish execution.
static void	init_threads(t_sim *sim)
{
	unsigned int	i;

	i = 0;
	print_top();
	pthread_create(&sim->monitor, NULL, &routine_monitor, &sim->philos);
	while (i < sim->stats.nbr_of_philos)
	{
		sim->philos[i].id = i + 1;
		pthread_create(&sim->philos[i].thread, NULL, &routine, &sim->philos[i]);
		i++;
	}
	i = 0;
	while (i < sim->stats.nbr_of_philos)
	{
		pthread_join(sim->philos[i].thread, NULL);
		i++;
	}
	pthread_join(sim->monitor, NULL);
}

// Allocates the different iterations of philosophers.
// Initializes each philosopher's fork and links it to their neighbor's.
// (The last philosopher's neighboring fork is that of the first one!)
static void	init_mutexes(t_sim *sim)
{
	unsigned int	i;

	i = 0;
	while (i < sim->stats.nbr_of_philos)
	{
		sim->philos[i].stats = &sim->stats;
		pthread_mutex_init(&sim->philos[i].left_fork, NULL);
		pthread_mutex_init(&sim->philos[i].is_dead_mutex, NULL);
		if (i == sim->stats.nbr_of_philos - 1)
			sim->philos[i].right_fork = &sim->philos[0].left_fork;
		else
			sim->philos[i].right_fork = &sim->philos[i + 1].left_fork;
		i++;
	}
}

// Initializes the statistics struct based on the given arguments.
static void	init_stats(t_sim *sim, const char **argv)
{
	sim->stats.nbr_of_philos = ft_atou(argv[1]);
	if (sim->stats.nbr_of_philos > 200)
	{
		printf("\e[1;31m[x] - Error: \e[1;97mToo many philos!\n\e[0m");
		exit(1);
	}
	sim->stats.time_to_die = ft_atou(argv[2]);
	sim->stats.time_to_eat = ft_atou(argv[3]);
	sim->stats.time_to_sleep = ft_atou(argv[4]);
	if (argv[5])
		sim->stats.cycles = ft_atou(argv[5]);
	else
		sim->stats.cycles = 0;
	sim->stats.timestamp = ft_gettime();
}

int	main(int argc, const char **argv)
{
	t_sim	sim;

	if (!parser(argc, argv))
		return (1);
	init_stats(&sim, argv);
	init_mutexes(&sim);
	init_threads(&sim);
	return (0);
}

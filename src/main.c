/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flmarsou <flmarsou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 12:31:14 by flmarsou          #+#    #+#             */
/*   Updated: 2024/09/24 15:47:25 by flmarsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

// Initializes the philosophers' threads and destroys them afterward.
static void	init_threads(t_sim *sim)
{
	unsigned int	i;

	i = 0;
	while (i < sim->stats.nbr_of_philos)
	{
		pthread_create(&sim->philos[i].thread, NULL, &routine, &sim->philos[i]);
		i++;
	}
	i = 0;
	while (i < sim->stats.nbr_of_philos)
	{
		pthread_join(sim->philos[i].thread, NULL);
		i++;
	}
}

// Initializes the philosophers' fork and links the address of their neighbor's.
static void	init_mutexes(t_sim *sim)
{
	unsigned int	i;

	i = 0;
	sim->philos = malloc(sizeof(struct s_philos) * sim->stats.nbr_of_philos);
	while (i < sim->stats.nbr_of_philos)
	{
		sim->philos[i].id = i;
		pthread_mutex_init(&sim->philos[i].left_fork, NULL);
		if (i == sim->stats.nbr_of_philos - 1)
			sim->philos[i].right_fork = &sim->philos[0].left_fork;
		else
			sim->philos[i].right_fork = &sim->philos[i + 1].left_fork;
		i++;
	}
}

static void	init_stats(t_sim *sim, const char **argv)
{
	sim->stats.nbr_of_philos = ft_atou(argv[1]);
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
	free(sim.philos);
	return (0);
}

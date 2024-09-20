/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flmarsou <flmarsou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 12:31:14 by flmarsou          #+#    #+#             */
/*   Updated: 2024/09/20 13:07:18 by flmarsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	*philosopher_routine(void *arg)
{
	struct s_philos		*philo = (struct s_philos *)arg;
	
	printf("Philo %u exists!\n", philo->id);
	fflush(stdout);
	return (0);
}

void	init_philos(t_sim *sim)
{
	unsigned int	i;

	i = 0;
	sim->philos = malloc(sizeof(struct s_philos) * sim->stats.nbr_of_philos);
	if (!sim->philos)
		exit(1);
	while (i < sim->stats.nbr_of_philos)
	{
		sim->philos[i].id = i;
		pthread_create(&sim->philos[i].thread, NULL, philosopher_routine, &sim->philos[i]);
		i++;
	}
}

void	init_stats(t_sim *sim, const char **argv)
{
	sim->stats.nbr_of_philos = ft_atou(argv[1]);
	sim->stats.time_to_die = ft_atou(argv[2]);
	sim->stats.time_to_eat = ft_atou(argv[3]);
	sim->stats.time_to_sleep = ft_atou(argv[4]);
	if (argv[5])
		sim->stats.cycles = ft_atou(argv[5]);
	else
		sim->stats.cycles = 0;
	sim->stats.timestamp = gettime();
}

int	main(int argc, const char **argv)
{
	t_sim	sim;

	if (!parser(argc, argv))
		return (1);
	init_stats(&sim, argv);
	init_philos(&sim);
	return (0);
}

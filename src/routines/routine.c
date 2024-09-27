/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flmarsou <flmarsou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 15:03:30 by flmarsou          #+#    #+#             */
/*   Updated: 2024/09/27 13:10:35 by flmarsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

void	*routine(void *arg)
{
	t_philos	*philo;

	philo = (t_philos *)arg;
	while (!philo->stats->key)
		usleep(100);
	if (philo->id % 2 == 0)
	{
		printer((ft_gettime() - philo->stats->timestamp), philo->id, 4);
		usleep(100);
	}
	philo->ate = 0;
	while (!philo->stats->is_dead)
	{
		// EATING
		if (!philo->ate)
		{
			pthread_mutex_lock(&philo->left_fork);
			pthread_mutex_lock(philo->right_fork);
			pthread_mutex_lock(&philo->stats->died);
			if (!philo->stats->is_dead)
			{
				printer((ft_gettime() - philo->stats->timestamp), philo->id, 1);
				printer((ft_gettime() - philo->stats->timestamp), philo->id, 1);
				printer((ft_gettime() - philo->stats->timestamp), philo->id, 2);
			}
			pthread_mutex_unlock(&philo->stats->died);
			philo->time_left = ft_gettime();
			rest(philo->stats->time_to_eat, philo);
			philo->ate = 1;
			pthread_mutex_unlock(&philo->left_fork);
			pthread_mutex_unlock(philo->right_fork);
		}

		// SLEEPING
		pthread_mutex_lock(&philo->stats->died);
		if (!philo->stats->is_dead)
			printer((ft_gettime() - philo->stats->timestamp), philo->id, 3);
		pthread_mutex_unlock(&philo->stats->died);
		rest(philo->stats->time_to_sleep, philo);
		philo->ate = 0;

		// THINKING
		if (!philo->stats->is_dead)
			printer((ft_gettime() - philo->stats->timestamp), philo->id, 4);
	}
	return (0);
}

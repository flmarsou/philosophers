/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flmarsou <flmarsou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 15:03:30 by flmarsou          #+#    #+#             */
/*   Updated: 2024/11/20 13:37:42 by flmarsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

static void	*one_philo(t_philos *philo)
{
	printer(0, 1, THINK);
	printer((ft_gettime() - philo->stats->timestamp), 1, FORK);
	rest(philo->stats->time_to_die, philo);
	printer((ft_gettime() - philo->stats->timestamp), 1, DEAD);
	return (NULL);
}

void	*routine(void *arg)
{
	t_philos		*philo;

	philo = (t_philos *)arg;
	if (philo->stats->nbr_of_philos == 1)
		return (one_philo(philo));
	if (philo->id % 2 == 0)
		usleep(1000);
	while (true)
	{
		pthread_mutex_lock(&philo->stats->lock);
		if (philo->stats->stop)
		{
			pthread_mutex_unlock(&philo->stats->lock);
			return (NULL);
		}
		pthread_mutex_unlock(&philo->stats->lock);
		printer((ft_gettime() - philo->stats->timestamp), philo->id, THINK);
		ft_eat(philo);
		ft_sleep(philo);
	}
	return (NULL);
}

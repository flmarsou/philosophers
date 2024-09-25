/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flmarsou <flmarsou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 15:03:30 by flmarsou          #+#    #+#             */
/*   Updated: 2024/09/25 15:59:05 by flmarsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

void	routine_eat(t_philos *philo)
{
	if (philo->ate)
		return ;
	pthread_mutex_lock(&philo->left_fork);
	pthread_mutex_lock(philo->right_fork);
	printf("Current time: %lu | Philo ID: %u ate.\n", ft_gettime() - philo->stats->timestamp, philo->id);
	ft_msleep(philo->stats->time_to_eat);
	philo->ate = 1;
	pthread_mutex_unlock(&philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
}

void	*routine(void *arg)
{
	t_philos	*philo;

	philo = (t_philos *)arg;
	while (1)
		if (philo->stats->key)
			break ;
	if (philo->id % 2 == 0)
		usleep(1000);
	philo->ate = 0;
	while (1)
	{
		routine_eat(philo);
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_eat.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flmarsou <flmarsou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 10:30:27 by flmarsou          #+#    #+#             */
/*   Updated: 2024/11/13 15:11:37 by flmarsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

void	routine_eat(t_philos *philo)
{
	if (&philo->left_fork < philo->right_fork)
	{
		pthread_mutex_lock(&philo->left_fork);
		pthread_mutex_lock(philo->right_fork);
	}
	else
	{
		pthread_mutex_lock(philo->right_fork);
		pthread_mutex_lock(&philo->left_fork);
	}
	if (philo->is_dead == false)
	{
		printer((ft_gettime() - philo->stats->timestamp), philo->id, FORK);
		printer((ft_gettime() - philo->stats->timestamp), philo->id, FORK);
		printer((ft_gettime() - philo->stats->timestamp), philo->id, EAT);
		philo->time_left = ft_gettime();
		rest(philo->stats->time_to_eat);
	}
	pthread_mutex_unlock(&philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
}

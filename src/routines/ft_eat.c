/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flmarsou <flmarsou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 09:46:06 by flmarsou          #+#    #+#             */
/*   Updated: 2024/11/20 13:10:22 by flmarsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

void	ft_eat(t_philos *philo)
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
	pthread_mutex_lock(&philo->stats->lock);
	if (!philo->stats->stop)
	{
		printer((ft_gettime() - philo->stats->timestamp), philo->id, FORK);
		printer((ft_gettime() - philo->stats->timestamp), philo->id, FORK);
		printer((ft_gettime() - philo->stats->timestamp), philo->id, EAT);
	}
	pthread_mutex_unlock(&philo->stats->lock);
	philo->time_left = ft_gettime();
	rest(philo->stats->time_to_eat, philo);
	pthread_mutex_unlock(&philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
}

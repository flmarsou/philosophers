/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flmarsou <flmarsou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 09:46:06 by flmarsou          #+#    #+#             */
/*   Updated: 2024/11/22 11:22:34 by flmarsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

static void	left_fork_first(t_philos *philo)
{
	pthread_mutex_lock(&philo->left_fork);
	pthread_mutex_lock(&philo->stats->lock);
	if (!philo->stats->stop)
		printer((ft_gettime() - philo->stats->timestamp), philo->id, FORK);
	pthread_mutex_unlock(&philo->stats->lock);
	pthread_mutex_lock(philo->right_fork);
	pthread_mutex_lock(&philo->stats->lock);
	if (!philo->stats->stop)
		printer((ft_gettime() - philo->stats->timestamp), philo->id, FORK);
	pthread_mutex_unlock(&philo->stats->lock);
}

static void	right_fork_first(t_philos *philo)
{
	pthread_mutex_lock(philo->right_fork);
	pthread_mutex_lock(&philo->stats->lock);
	if (!philo->stats->stop)
		printer((ft_gettime() - philo->stats->timestamp), philo->id, FORK);
	pthread_mutex_unlock(&philo->stats->lock);
	pthread_mutex_lock(&philo->left_fork);
	pthread_mutex_lock(&philo->stats->lock);
	if (!philo->stats->stop)
		printer((ft_gettime() - philo->stats->timestamp), philo->id, FORK);
	pthread_mutex_unlock(&philo->stats->lock);
}

void	ft_eat(t_philos *philo)
{
	if (&philo->left_fork < philo->right_fork)
		left_fork_first(philo);
	else
		right_fork_first(philo);
	pthread_mutex_lock(&philo->stats->lock);
	if (!philo->stats->stop)
		printer((ft_gettime() - philo->stats->timestamp), philo->id, EAT);
	philo->time_left = ft_gettime();
	philo->meals++;
	pthread_mutex_unlock(&philo->stats->lock);
	rest(philo->stats->time_to_eat, philo);
	pthread_mutex_unlock(&philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
}

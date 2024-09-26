/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_eat.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flmarsou <flmarsou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 10:30:27 by flmarsou          #+#    #+#             */
/*   Updated: 2024/09/26 16:00:26 by flmarsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

void	routine_eat(t_philos *philo)
{
	if (philo->ate)
		return ;
	pthread_mutex_lock(&philo->left_fork);
	pthread_mutex_lock(philo->right_fork);
	printer((ft_gettime() - philo->stats->timestamp), philo->id, 1);
	printer((ft_gettime() - philo->stats->timestamp), philo->id, 1);
	printer((ft_gettime() - philo->stats->timestamp), philo->id, 2);
	rest(philo->stats->time_to_eat);
	philo->ate = 1;
	pthread_mutex_unlock(&philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
}

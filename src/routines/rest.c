/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rest.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flmarsou <flmarsou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 14:38:21 by flmarsou          #+#    #+#             */
/*   Updated: 2024/11/20 12:48:10 by flmarsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

// Uses multiple short usleep() for a more accurate wait time (in miliseconds).
void	rest(unsigned int time_to_wait, t_philos *philo)
{
	unsigned long	current_time;

	current_time = ft_gettime();
	while (ft_gettime() - current_time < time_to_wait)
	{
		pthread_mutex_lock(&philo->stats->lock);
		if (philo->stats->stop)
		{
			pthread_mutex_unlock(&philo->stats->lock);
			return ;
		}
		pthread_mutex_unlock(&philo->stats->lock);
		usleep(60);
	}
}

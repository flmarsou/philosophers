/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sleep.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flmarsou <flmarsou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 09:46:37 by flmarsou          #+#    #+#             */
/*   Updated: 2024/11/20 09:40:09 by flmarsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

void	ft_sleep(t_philos *philo)
{
	pthread_mutex_lock(&philo->stats->lock);
	if (!philo->stats->stop)
		printer((ft_gettime() - philo->stats->timestamp), philo->id, SLEEP);
	pthread_mutex_unlock(&philo->stats->lock);
	rest(philo->stats->time_to_sleep, philo);
}

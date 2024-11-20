/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_monitor.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flmarsou <flmarsou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 10:43:31 by flmarsou          #+#    #+#             */
/*   Updated: 2024/11/20 13:43:38 by flmarsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

void	*routine_monitor(void *arg)
{
	t_philos		*philos;
	unsigned int	i;

	philos = (t_philos *)arg;
	i = 0;
	while (true)
	{
		i = 0;
		while (i < philos->stats->nbr_of_philos)
		{
			pthread_mutex_lock(&philos->stats->lock);
			if (ft_gettime() - philos[i].time_left > philos->stats->time_to_die)
			{
				philos->stats->stop = true;
				printer((ft_gettime() - philos->stats->timestamp), philos->id, DEAD);
				pthread_mutex_unlock(&philos->stats->lock);
				return (NULL);
			}
			i++;
			pthread_mutex_unlock(&philos->stats->lock);
		}
		usleep(500);
	}
	return (NULL);
}

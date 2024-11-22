/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_monitor.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flmarsou <flmarsou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 10:43:31 by flmarsou          #+#    #+#             */
/*   Updated: 2024/11/22 12:25:26 by flmarsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

static bool	count_meals(t_philos *philos)
{
	unsigned int	i;

	i = 0;
	while (i < philos->stats->nbr_of_philos
		&& philos[i].meals >= philos->stats->cycles)
		i++;
	if (i == philos->stats->nbr_of_philos)
	{
		philos->stats->stop = true;
		pthread_mutex_unlock(&philos->stats->lock);
		printf(END_PRINT);
		return (true);
	}
	return (false);
}

void	*routine_monitor(void *arg)
{
	t_philos		*philos;
	unsigned int	i;

	philos = (t_philos *)arg;
	while (true)
	{
		i = -1;
		pthread_mutex_lock(&philos->stats->lock);
		while (++i < philos->stats->nbr_of_philos)
		{
			if (ft_gettime() - philos[i].time_left > philos->stats->time_to_die)
			{
				philos->stats->stop = true;
				printer(ft_gettime() - philos->stats->timestamp,
					philos->id, DEAD);
				pthread_mutex_unlock(&philos->stats->lock);
				return (NULL);
			}
		}
		if (count_meals(philos))
			return (NULL);
		pthread_mutex_unlock(&philos->stats->lock);
		usleep(500);
	}
	return (NULL);
}

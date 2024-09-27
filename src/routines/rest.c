/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rest.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flmarsou <flmarsou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 14:38:21 by flmarsou          #+#    #+#             */
/*   Updated: 2024/09/27 13:01:26 by flmarsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

static t_bool	is_dead(t_philos *philo)
{
	if (ft_gettime() - philo->time_left > philo->stats->time_to_die)
	{
		pthread_mutex_lock(&philo->stats->died);
		if (philo->stats->is_dead == 0)
			printer((ft_gettime() - philo->stats->timestamp), philo->id, 5);
		philo->stats->is_dead = 1;
		pthread_mutex_unlock(&philo->stats->died);
		return (true);
	}
	return (false);
}

// Uses multiple short usleep() for a more accurate wait time (in miliseconds).
void	rest(unsigned int time_to_wait, t_philos *philo)
{
	unsigned long	current_time;

	current_time = ft_gettime();
	while (ft_gettime() - current_time < time_to_wait)
	{
		if (is_dead(philo))
			return ;
		usleep(60);
	}
}

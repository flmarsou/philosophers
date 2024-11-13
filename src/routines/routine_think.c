/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_think.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flmarsou <flmarsou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 10:12:49 by flmarsou          #+#    #+#             */
/*   Updated: 2024/11/13 14:48:40 by flmarsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

void	routine_think(t_philos *philo)
{
	if (philo->is_dead == false)
	{
		printer((ft_gettime() - philo->stats->timestamp), philo->id, THINK);
		if (philo->stats->time_to_sleep > philo->stats->time_to_eat)
			rest(philo->stats->time_to_sleep - philo->stats->time_to_eat);
		else
			rest(philo->stats->time_to_eat - philo->stats->time_to_sleep);
	}
}

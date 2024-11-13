/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flmarsou <flmarsou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 15:03:30 by flmarsou          #+#    #+#             */
/*   Updated: 2024/11/13 15:11:00 by flmarsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

void	*routine(void *arg)
{
	t_philos	*philo;

	philo = (t_philos *)arg;
	if (philo->id % 2 == 0)
		rest(philo->stats->time_to_eat);
	while (philo->is_dead == false)
	{
		routine_eat(philo);
		routine_sleep(philo);
		routine_think(philo);
	}
	return (NULL);
}

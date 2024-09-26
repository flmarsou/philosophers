/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flmarsou <flmarsou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 15:03:30 by flmarsou          #+#    #+#             */
/*   Updated: 2024/09/26 11:17:58 by flmarsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

void	*routine(void *arg)
{
	t_philos	*philo;

	philo = (t_philos *)arg;
	while (1)
		if (philo->stats->key)
			break ;
	if (philo->id % 2 == 0)
		usleep(1000);
	philo->ate = 0;
	while (1)
	{
		routine_eat(philo);
		routine_sleep(philo);
	}
	return (0);
}

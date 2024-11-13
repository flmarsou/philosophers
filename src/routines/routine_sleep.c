/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_sleep.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flmarsou <flmarsou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 10:30:48 by flmarsou          #+#    #+#             */
/*   Updated: 2024/11/13 14:48:36 by flmarsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

void	routine_sleep(t_philos *philo)
{
	if (philo->is_dead == false)
	{
		printer((ft_gettime() - philo->stats->timestamp), philo->id, SLEEP);
		rest(philo->stats->time_to_sleep);
	}
}

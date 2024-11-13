/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_monitor.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flmarsou <flmarsou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 10:43:31 by flmarsou          #+#    #+#             */
/*   Updated: 2024/11/13 15:10:47 by flmarsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

void	*routine_monitor(void *arg)
{
	t_philos		*philo;

	philo = (t_philos *)arg;
	while (true)
	{
		sleep(1);
	}
	return (NULL);
}

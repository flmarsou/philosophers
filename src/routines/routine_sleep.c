/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_sleep.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flmarsou <flmarsou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 10:30:48 by flmarsou          #+#    #+#             */
/*   Updated: 2024/09/27 12:16:30 by flmarsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

void	routine_sleep(t_philos *philo)
{
	printer((ft_gettime() - philo->stats->timestamp), philo->id, 3);
	rest(philo->stats->time_to_sleep);
	printer((ft_gettime() - philo->stats->timestamp), philo->id, 4);
	philo->ate = 0;
}
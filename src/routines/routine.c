/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flmarsou <flmarsou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 15:03:30 by flmarsou          #+#    #+#             */
/*   Updated: 2024/09/24 15:44:09 by flmarsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

void	*routine(void *arg)
{
	struct s_philos	*philo;

	philo = (struct s_philos *)arg;
	while (1)
	{
		pthread_mutex_lock(&philo->left_fork);
		pthread_mutex_lock(philo->right_fork);
		printf("║	%d	║ has taken a fork ║\n", philo->id);
		printf("║	%d	║ is eating        ║\n", philo->id);
		pthread_mutex_unlock(&philo->left_fork);
		pthread_mutex_unlock(philo->right_fork);
		printf("║	%d	║ is sleeping      ║\n", philo->id);
		printf("║		║                  ║\n");
		sleep(1);
	}
	return (0);
}

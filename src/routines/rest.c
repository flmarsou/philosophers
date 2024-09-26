/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flmarsou <flmarsou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 14:38:21 by flmarsou          #+#    #+#             */
/*   Updated: 2024/09/26 14:13:56 by flmarsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

// Uses multiple short usleep() for a more accurate wait time (in miliseconds).
void	rest(unsigned int time_to_wait)
{
	unsigned long	current_time;

	current_time = ft_gettime();
	while (ft_gettime() - current_time < time_to_wait)
		usleep(60);
}

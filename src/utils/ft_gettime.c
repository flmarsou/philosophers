/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gettime.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flmarsou <flmarsou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 11:10:10 by flmarsou          #+#    #+#             */
/*   Updated: 2024/09/23 15:05:13 by flmarsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

// current_seconds:		Converts seconds to miliseconds.
// current_miliseconds:	Converts microseconds to miliseconds.
unsigned long	ft_gettime(void)
{
	struct timeval	timestamp;
	unsigned long	current_seconds;
	unsigned long	current_miliseconds;

	gettimeofday(&timestamp, NULL);
	current_seconds = timestamp.tv_sec * 1000;
	current_miliseconds = timestamp.tv_usec / 1000;
	return (current_seconds + current_miliseconds);
}

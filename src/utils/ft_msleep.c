/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_msleep.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flmarsou <flmarsou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 14:38:21 by flmarsou          #+#    #+#             */
/*   Updated: 2024/09/25 15:48:52 by flmarsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

void	ft_msleep(unsigned int time_to_wait)
{
	unsigned long	current_time;

	current_time = ft_gettime();
	while (ft_gettime() - current_time < time_to_wait)
		usleep(60);
}

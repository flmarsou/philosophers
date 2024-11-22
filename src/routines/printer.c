/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flmarsou <flmarsou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 10:47:28 by flmarsou          #+#    #+#             */
/*   Updated: 2024/11/22 11:16:59 by flmarsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

// Fancy Printer
void	printer(unsigned long time, unsigned int id, unsigned int act)
{
	if (act == FORK)
		printf(DISPLAY_PRINT, time, id, FORK_PRINT);
	else if (act == EAT)
		printf(DISPLAY_PRINT, time, id, EAT_PRINT);
	else if (act == SLEEP)
		printf(DISPLAY_PRINT, time, id, SLEEP_PRINT);
	else if (act == THINK)
		printf(DISPLAY_PRINT, time, id, THINK_PRINT);
	else
	{
		printf(DISPLAY_PRINT, time, id, DEAD_PRINT);
		printf(END_PRINT);
	}
}

// Normal Printer
// void	printer(unsigned long time, unsigned int id, unsigned int act)
// {
// 	if (act == FORK)
// 		printf("%lu %u has taken a fork\n", time, id);
// 	else if (act == EAT)
// 		printf("%lu %u is eating\n", time, id);
// 	else if (act == SLEEP)
// 		printf("%lu %u is sleeping\n", time, id);
// 	else if (act == THINK)
// 		printf("%lu %u is thinking\n", time, id);
// 	else
// 		printf("%lu %u died\n", time, id);
// }

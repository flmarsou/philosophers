/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flmarsou <flmarsou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 10:47:28 by flmarsou          #+#    #+#             */
/*   Updated: 2024/11/21 12:04:58 by flmarsou         ###   ########.fr       */
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
// 	const char	fork[25] = "\e[1mhas taken a fork\e[0m";
// 	const char	eat[25] = "\e[1mis eating\e[0m";
// 	const char	sleep[25] = "\e[1mis sleeping\e[0m";
// 	const char	think[25] = "\e[1mis thinking\e[0m";
// 	const char	death[25] = "\e[1mdied\e[0m";

// 	if (act == FORK)
// 		printf("%lu %u %s\n", time, id, fork);
// 	else if (act == EAT)
// 		printf("%lu %u %s\n", time, id, eat);
// 	else if (act == SLEEP)
// 		printf("%lu %u %s\n", time, id, sleep);
// 	else if (act == THINK)
// 		printf("%lu %u %s\n", time, id, think);
// 	else
// 		printf("%lu %u %s\n", time, id, death);
// }

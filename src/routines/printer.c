/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flmarsou <flmarsou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 10:47:28 by flmarsou          #+#    #+#             */
/*   Updated: 2024/11/13 10:37:53 by flmarsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

void	printer(unsigned long time, unsigned int id, unsigned int act)
{
	const char	fork[25] = "\e[1mhas taken a fork\e[0m";
	const char	eat[25] = "\e[1mis eating\e[0m       ";
	const char	sleep[25] = "\e[1mis sleeping     \e[0m";
	const char	think[25] = "\e[1mis thinking     \e[0m";
	const char	death[25] = "\e[1mdied            \e[0m";

	if (act == FORK)
		printf("║ \e[1m%8lu\e[0m ║ \e[1m%8u\e[0m ║ %s ║\n", time, id, fork);
	else if (act == EAT)
		printf("║ \e[1m%8lu\e[0m ║ \e[1m%8u\e[0m ║ %s ║\n", time, id, eat);
	else if (act == SLEEP)
		printf("║ \e[1m%8lu\e[0m ║ \e[1m%8u\e[0m ║ %s ║\n", time, id, sleep);
	else if (act == THINK)
		printf("║ \e[1m%8lu\e[0m ║ \e[1m%8u\e[0m ║ %s ║\n", time, id, think);
	else
	{
		printf("║ \e[1m%8lu\e[0m ║ \e[1m%8u\e[0m ║ %s ║\n", time, id, death);
		printf("╚══════════╩══════════╩══════════════════╝\n");
	}
}

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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flmarsou <flmarsou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 10:47:28 by flmarsou          #+#    #+#             */
/*   Updated: 2024/09/26 15:17:48 by flmarsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

static void	print_top(void)
{
	printf("╔══════════╦══════════╦══════════════════╗\n");
	printf("║ \e[1mTime\e[0m     ║ \e[1mPhilo\e[0m    ║");
	printf(" \e[1mEvent\e[0m            ║\n");
	printf("╠══════════╬══════════╬══════════════════╣\n");
}

void	printer(unsigned long time, unsigned int id, unsigned int act)
{
	const char	fork[25] = "\e[1mhas taken a fork\e[0m";
	const char	eat[25] = "\e[1mis eating\e[0m       ";
	const char	sleep[25] = "\e[1mis sleeping     \e[0m";
	const char	think[25] = "\e[1mis thinking     \e[0m";
	const char	death[25] = "\e[1mdied            \e[0m";

	if (act == 0)
		print_top();
	else if (act == 1)
		printf("║ \e[1m%8lu\e[0m ║ \e[1m%8u\e[0m ║ %s ║\n", time, id, fork);
	else if (act == 2)
		printf("║ \e[1m%8lu\e[0m ║ \e[1m%8u\e[0m ║ %s ║\n", time, id, eat);
	else if (act == 3)
		printf("║ \e[1m%8lu\e[0m ║ \e[1m%8u\e[0m ║ %s ║\n", time, id, sleep);
	else if (act == 4)
		printf("║ \e[1m%8lu\e[0m ║ \e[1m%8u\e[0m ║ %s ║\n", time, id, think);
	else
	{
		printf("║ \e[1m%8lu\e[0m ║ \e[1m%8u\e[0m ║ %s ║\n", time, id, death);
		printf("╚══════════╩══════════╩══════════════════╝\n");
	}
}

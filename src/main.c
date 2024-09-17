/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flmarsou <flmarsou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 12:31:14 by flmarsou          #+#    #+#             */
/*   Updated: 2024/09/17 15:29:33 by flmarsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	main(int argc, const char **argv)
{
	if (!check_argv(argv + 1) || !check_argc(argc))
	{
		printf("\e[1;35m[!] - Usage: \e[1;97m<nbr_of_philo> ");
		printf("<time_to_die> <time_to_eat> <time_to_sleep>\n\e[0m");
		exit(1);
	}
	return (0);
}

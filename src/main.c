/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flmarsou <flmarsou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 12:31:14 by flmarsou          #+#    #+#             */
/*   Updated: 2024/09/16 16:07:50 by flmarsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static void	check_argc(int argc)
{
	if (argc < 5 || argc > 6)
	{
		if (argc == 1)
			printf("\e[1;31m[x] - Error: \e[1;97mMissing number of philosophers!\n\e[0m");
		if (argc == 2)
			printf("\e[1;31m[x] - Error: \e[1;97mMissing time to die!\n\e[0m");
		if (argc == 3)
			printf("\e[1;31m[x] - Error: \e[1;97mMissing time to eat!\n\e[0m");
		if (argc == 4)
			printf("\e[1;31m[x] - Error: \e[1;97mMissing time to sleep!\n\e[0m");
		if (argc == 7)
			printf("\e[1;31m[x] - Error: \e[1;97mToo many arguments!\n\e[0m");
		printf("\e[1;35m[!] - Usage: \e[1;97m<nbr_of_philo> <time_to_die> <time_to_eat> <time_to_sleep>\n\e[0m");
		exit (1);
	}
}

static void	check_argv(char **argv)
{
	
}

int	main(int argc, char const **argv)
{
	check_argc(argc);
	check_argv(argv);
	return (0);
}

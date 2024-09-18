/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flmarsou <flmarsou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 15:29:40 by flmarsou          #+#    #+#             */
/*   Updated: 2024/09/18 14:49:02 by flmarsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static t_bool	isnumber(const char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (false);
		i++;
	}
	return (true);
}

t_bool	check_argv(const char **argv)
{
	unsigned int	i;

	i = 1;
	while (argv[i])
	{
		if (!isnumber(argv[i]))
		{
			printf("\e[1;31m[x] - Error: \e[1;97mIncorect Arguments!\n\e[0m");
			return (false);
		}
		i++;
	}
	if (argv[5] && (argv[5][0] == '0' || !argv[5][0]))
	{
		printf("\e[1;31m[x] - Error: \e[1;97mCycles can't be zero!\n\e[0m");
		return (false);
	}
	return (true);
}

t_bool	check_argc(int argc)
{
	if (argc != 5 && argc != 6)
	{
		printf("\e[1;31m[x] - Error: \e[1;97m");
		if (argc == 1)
			printf("Missing number of philosophers!\n");
		if (argc == 2)
			printf("Missing time to die!\n");
		if (argc == 3)
			printf("Missing time to eat!\n");
		if (argc == 4)
			printf("Missing time to sleep!\n");
		if (argc >= 7)
			printf("Too many arguments!\n");
		return (false);
	}
	return (true);
}

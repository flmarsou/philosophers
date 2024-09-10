/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flmarsou <flmarsou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 12:32:28 by flmarsou          #+#    #+#             */
/*   Updated: 2024/09/10 15:45:29 by flmarsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <string.h>	// memset
# include <stdio.h>		// printf
# include <stdlib.h>	// malloc, free
# include <unistd.h>	// write, usleep
# include <sys/time.h>	// gettimeofday
# include <pthread.h>	// pthread_create, pthread_detach, pthread_join,
						// pthread_mutex_init, pthread_mutex_destroy
						// pthread_mutex_lock, pthread_mutex_unlock

struct s_stats
{
	unsigned int	nbr_of_philos;
	unsigned long	time_to_die;
	unsigned long	time_to_eat;
	unsigned long	time_to_sleep;
};

typedef struct s_philo
{
	struct s_stats	stats;
}	t_philo;

//===============================//
//             Utils             //
//===============================//

unsigned int	ft_atou(const char *str);
unsigned long	ft_atolu(const char *str);

//===============================//
//             Parser            //
//===============================//

void			parser(int argc, const char **argv);

#endif

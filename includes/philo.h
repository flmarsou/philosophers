/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flmarsou <flmarsou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 12:32:28 by flmarsou          #+#    #+#             */
/*   Updated: 2024/09/18 14:26:06 by flmarsou         ###   ########.fr       */
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

// Boolean
typedef enum e_bool
{
	false = 0,
	true = 1
}	t_bool;

struct s_stats
{
	unsigned int	nbr_of_philos;		// Number of Philosophers
	unsigned int	time_to_die;		// Time to die in miliseconds
	unsigned int	time_to_eat;		// Time to eat in miliseconds
	unsigned int	time_to_sleep;		// Time to sleep in miliseconds
	unsigned int	cycles;				// Number of cycles
};

typedef struct s_philo
{
	struct s_stats	stats;
}	t_philo;

//===============================//
//             Utils             //
//===============================//

unsigned int	ft_atou(const char *str);

//===============================//
//             Parser            //
//===============================//

t_bool			check_argc(int argc);
t_bool			check_argv(const char **argv);

#endif

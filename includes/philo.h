/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flmarsou <flmarsou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 12:32:28 by flmarsou          #+#    #+#             */
/*   Updated: 2024/09/27 13:00:12 by flmarsou         ###   ########.fr       */
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

// Philosophers' Stats
struct s_stats
{
	unsigned int	nbr_of_philos;	// Number of Philosophers
	unsigned int	time_to_die;	// Time to die in miliseconds
	unsigned int	time_to_eat;	// Time to eat in miliseconds
	unsigned int	time_to_sleep;	// Time to sleep in miliseconds
	unsigned int	cycles;			// Number of cycles
	unsigned long	timestamp;		// Current time in milisecond
	t_bool			key;			// Bool to wait for all threads to init
	t_bool			is_dead;		// Bool to check if a philosopher died
	pthread_mutex_t	died;
};

// Philosophers' Info (Individual Allocation)
typedef struct s_philos
{
	unsigned int	id;				// Philosophers' ID
	pthread_mutex_t	left_fork;		// Philosophers' Fork
	pthread_mutex_t	*right_fork;	// Philosophers' Neighbor Fork
	pthread_t		thread;			// Philosophers' Thread
	t_bool			ate;			// Bool to check if a philosopher ate
	unsigned long	time_left;
	struct s_stats	*stats;
}	t_philos;

// Main Struct
typedef struct s_sim
{
	struct s_stats	stats;
	struct s_philos	*philos;			// Array of Philosophers
}	t_sim;

//===============================//
//             Utils             //
//===============================//
unsigned int	ft_atou(const char *str);
unsigned long	ft_gettime(void);

//===============================//
//             Parser            //
//===============================//
t_bool			parser(int argc, const char **argv);

//===============================//
//            Threads            //
//===============================//
void			*routine(void *arg);
// void			routine_eat(t_philos *philo);
// void			routine_sleep(t_philos *philo);
void			rest(unsigned int time_to_wait, t_philos *philo);
void			printer(unsigned long time, unsigned int id, unsigned int act);

#endif

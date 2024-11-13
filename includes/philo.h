/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flmarsou <flmarsou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 12:32:28 by flmarsou          #+#    #+#             */
/*   Updated: 2024/11/13 14:48:22 by flmarsou         ###   ########.fr       */
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
# include <stdbool.h>	// Booleans

// Action Enums
typedef enum e_actions
{
	FORK,
	EAT,
	SLEEP,
	THINK,
	DEAD
}	t_actions;

// Philosophers' Stats
struct s_stats
{
	unsigned int	nbr_of_philos;	// Number of Philosophers
	unsigned int	time_to_die;	// Time to die in miliseconds
	unsigned int	time_to_eat;	// Time to eat in miliseconds
	unsigned int	time_to_sleep;	// Time to sleep in miliseconds
	unsigned int	cycles;			// Number of cycles
	unsigned long	timestamp;		// Current time in milisecond
};

// Philosophers' Info (Individual Allocation)
typedef struct s_philos
{
	unsigned int	id;				// Philosophers' ID
	pthread_mutex_t	left_fork;		// Philosophers' Fork
	pthread_mutex_t	*right_fork;	// Philosophers' Neighbor Fork
	pthread_t		thread;			// Philosophers' Thread
	unsigned long	time_left;		// Time left before dying
	bool			is_dead;		// Bool to check if a philosopher died
	pthread_mutex_t	is_dead_mutex;
	struct s_stats	*stats;
}	t_philos;

// Main Struct
typedef struct s_sim
{
	pthread_t		monitor;		// Monitor thread that checks for death
	struct s_stats	stats;
	struct s_philos	philos[200];	// Array of Philosophers
}	t_sim;

//===============================//
//             Utils             //
//===============================//

unsigned int	ft_atou(const char *str);
unsigned long	ft_gettime(void);

//===============================//
//             Parser            //
//===============================//

bool			parser(int argc, const char **argv);

//===============================//
//            Threads            //
//===============================//

void			*routine_monitor(void *arg);
void			*routine(void *arg);

void			routine_eat(t_philos *philo);
void			routine_sleep(t_philos *philo);
void			routine_think(t_philos *philo);

void			rest(unsigned int time_to_wait);

void			printer(unsigned long time, unsigned int id, unsigned int act);

#endif

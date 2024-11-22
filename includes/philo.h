/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flmarsou <flmarsou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 12:32:28 by flmarsou          #+#    #+#             */
/*   Updated: 2024/11/22 11:22:21 by flmarsou         ###   ########.fr       */
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

// Defines
# define DISPLAY_PRINT	"║ \e[1m%8lu\e[0m ║ \e[1m%8u\e[0m ║ %s ║\n"
# define FORK_PRINT		"\e[34;1mhas taken a fork\e[0m"
# define EAT_PRINT		"\e[32;1mis eating\e[0m       "
# define SLEEP_PRINT	"\e[35;1mis sleeping     \e[0m"
# define THINK_PRINT	"\e[1mis thinking...  \e[0m"
# define DEAD_PRINT		"\e[31;1mdied            \e[0m"
# define END_PRINT		"╚══════════╩══════════╩══════════════════╝\n"

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
	pthread_mutex_t	lock;			// Global Mutex
	bool			stop;			// Stops the simulation
};

// Philosophers' Info (Individual Allocation)
typedef struct s_philos
{
	struct s_stats	*stats;
	unsigned int	id;				// Philosophers' ID
	pthread_mutex_t	left_fork;		// Philosophers' Fork
	pthread_mutex_t	*right_fork;	// Philosophers' Neighbor Fork
	pthread_t		thread;			// Philosophers' Thread
	unsigned long	time_left;		// Time left before dying
	unsigned long	meals;			// Amounts of meals eaten
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

void			ft_eat(t_philos *philo);
void			ft_sleep(t_philos *philo);

void			rest(unsigned int time_to_wait, t_philos *philo);

void			printer(unsigned long time, unsigned int id, unsigned int act);

#endif

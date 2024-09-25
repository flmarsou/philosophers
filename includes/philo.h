/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flmarsou <flmarsou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 12:32:28 by flmarsou          #+#    #+#             */
/*   Updated: 2024/09/25 15:56:41 by flmarsou         ###   ########.fr       */
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
	unsigned int	key;			// Switch to wait for all threads to init
	unsigned long	timestamp;		// Current time in milisecond
};

// Philosophers' Info (Individual Allocation)
typedef struct s_philos
{
	pthread_t		thread;			// Philosophers' Thread
	unsigned int	id;				// Philosophers' ID
	pthread_mutex_t	left_fork;		// Philosophers' Fork
	pthread_mutex_t	*right_fork;	// Philosophers' Neighbor Fork
	unsigned int	ate;
	struct s_stats	*stats;
}	t_philos;

// Main Struct
typedef struct s_sim
{
	struct s_stats	stats;
	struct s_philos	*philos;			// Array of Philosophers
}	t_sim;

unsigned int	ft_atou(const char *str);
unsigned long	ft_gettime(void);
void			ft_msleep(unsigned int time_to_wait);

t_bool			parser(int argc, const char **argv);

void			*routine(void *philo);

#endif

// void	print_header(void)
// {
// 	printf("╔══════════╦═══════════╦══════════════════╗\n");
// 	printf("║ Time     ║ Philo     ║ Event            ║\n");
// 	printf("╠══════════╬═══════════╬══════════════════╣\n");
// 	printf("║ _______0 ║           ║ has taken a fork ║\n");
// 	printf("║ _____200 ║           ║ is eating        ║\n");
// 	printf("║ _____300 ║           ║ is sleeping      ║\n");
// 	printf("║ ____1000 ║           ║ is thinking      ║\n");
// 	printf("║ ____1200 ║           ║ died             ║\n");
// 	printf("╚══════════╩═══════════╩══════════════════╝\n");
// }

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamalmar <hamalmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 16:18:08 by hamad             #+#    #+#             */
/*   Updated: 2025/02/20 22:40:38 by hamalmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H
# include <pthread.h>

typedef struct s_prog	t_prog;

/**
 * @brief Structure to hold the information of the philosophers.
 * @var id The id of the philosopher.
 * @var n_meals The number of meals the philosopher has eaten (Optional).
 * var	tid The thread id of the philosopher.
 * @var	last_meal Time since eaten.
 * @var mfork The mutex fork of the philosopher.
 */
typedef struct s_philo
{
	long			id;
	long			n_meals;
	pthread_t		tid;
	long			last_meal;
	t_prog			*prog;
}	t_philo;

/**
 * @brief Structure to hold the information of the program.
 * @var n_philo The number of philosophers.
 * @var	td The time to die (time in milliseconds).
 * @var te The time to eat (time in milliseconds).
 * @var ts The time to sleep (time in milliseconds).
 * @var neat The number of eatings. (optional)
 * @var time The time since the start of the simulation.
 * @var dead_philo This will be 1 if we found a dead philosopher and will end
 * 	the simulation.
 * @var	forks	fork status.
 * @var	monitor The monitor thread.
 * @var	mforks The mutex forks.
 * @var	print The print mutex.
 * @var philo The array of philosophers.
 */
typedef struct s_prog
{
	int				n_philo;
	long			td;
	long			te;
	long			ts;
	int				neat;
	long			time;
	int				dead_philo;
	int				*forks;
	pthread_t		monitor;
	pthread_mutex_t	*mforks;
	pthread_mutex_t	print;
	pthread_mutex_t	dead;
	pthread_mutex_t	eat;
	t_philo			*philo;
}	t_prog;

enum e_activities
{
	e_pick_up_fork,
	e_eat,
	e_think,
	e_sleep,
	e_dead
};

#endif
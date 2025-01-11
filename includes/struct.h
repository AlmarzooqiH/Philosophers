/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamad <hamad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 16:18:08 by hamad             #+#    #+#             */
/*   Updated: 2025/01/11 17:23:38 by hamad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H
# include <pthread.h>

/**
 * @brief Structure to hold the information of the philosophers.
 * @var id The id of the philosopher.
 * var	tid The thread id of the philosopher.
 * @var lh The status of the left hand. (If it has the fork).
 * @var rh The status of the right hand. (If it has the fork).
 * @var mstf milliseconds when he took the fork.
 * @var mse milliseconds when he started eating.
 * @var mss milliseconds when he started sleeping.
 * @var mst milliseconds when he started thinking.
 * @var msd milliseconds when he died.
 * @var mfork The mutex fork of the philosopher.
 */
typedef struct s_philo
{
	int				id;
	pthread_t		tid;
	int				lh;
	int				rh;
	long			mstf;
	long			mse;
	long			mss;
	long			mst;
	long			msd;
	pthread_mutex_t	mfork;
}	t_philo;

/**
 * @brief Structure to hold the information of the program.
 * @var n_philo The number of philosophers.
 * @var	td The time to die (time in milliseconds).
 * @var te The time to eat (time in milliseconds).
 * @var ts The time to sleep (time in milliseconds).
 * @var neat The number of eatings. (optional)
 * @var time The time when the simulation started/ended.
 * @var philo The array of philosophers.
 */
typedef struct s_prog
{
	int		n_philo;
	long	time;
	long	td;
	long	te;
	long	ts;
	int		neat;
	t_philo	*philo;
}	t_prog;

#endif
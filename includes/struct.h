/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamad <hamad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 16:18:08 by hamad             #+#    #+#             */
/*   Updated: 2025/02/08 11:09:45 by hamad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H
# include <pthread.h>

typedef struct s_prog	t_prog;

/**
 * @brief Structure to hold the information of the philosophers.
 * @var id The id of the philosopher.
 * var	tid The thread id of the philosopher.
 * @var lh The status of the left hand. (If it has the fork).
 * @var rh The status of the right hand. (If it has the fork).
 * @var es The eating status of the philosopher.
 * @var ts The thinking status of the philosopher.
 * @var ss The sleeping status of the philosopher.
 * @var ds The dying status of the philosopher.
 * @var mstf milliseconds when he took the fork.
 * @var mse milliseconds when he started eating.
 * @var mss milliseconds when he started sleeping.
 * @var mst milliseconds when he started thinking.
 * @var msd milliseconds when he died.
 * @var	tse Time since eaten.
 * @var mfork The mutex fork of the philosopher.
 */
typedef struct s_philo
{
	long			id;
	pthread_t		tid;
	int				lh;
	int				rh;
	int				es;
	int				ts;
	int				ss;
	int				ds;
	long			mstf;
	long			mse;
	long			mss;
	long			mst;
	long			msd;
	long			tse;
	t_prog			*prog;
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
	int				n_philo;
	int				status;
	long			time;
	long			td;
	long			te;
	long			ts;
	int				neat;
	pthread_t		monitor;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print;
	t_philo			*philo;
}	t_prog;

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamad <hamad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 12:20:04 by hamad             #+#    #+#             */
/*   Updated: 2025/01/10 20:51:03 by hamad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H
# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>

/**
 * @brief Structure to hold the information of the philosophers.
 * @var id The id of the philosopher.
 * @var lh The status of the left hand. (If it has the fork).
 * @var rh The status of the right hand. (If it has the fork).
 * @var mstf milliseconds when he took the fork.
 * @var mse milliseconds when he started eating.
 * @var mss milliseconds when he started sleeping.
 * @var mst milliseconds when he started thinking.
 * @var msd milliseconds when he died.
 */
typedef struct s_philo
{
	int		id;
	int		lh;
	int		rh;
	long	mstf;
	long	mse;
	long	mss;
	long	mst;
	long	msd;
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

long	ft_atol(const char *str);
#endif